#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(NNPoints* points, int activation_function,
	int class_num, int layer_num, double learning_constant, double momentum_constant) {

	this->points = points;
	this->gradients = new Matrix[layer_num];
	this->activation_function = activation_function;
	this->class_num = class_num;
	this->layer_num = layer_num;
	this->learning_constant = learning_constant;
	this->momentum_constant = momentum_constant;
	this->sample_size = points->get_size();
	
	// Create input matrix
	this->data = new Matrix(INPUT_DIM, sample_size);

	// Create one-hot encoded label matrix
	this->labels = new Matrix(class_num, sample_size);

	// Create weight matrices
	// First create weight matrix of first layer
	this->weights.push_back(Matrix(class_num, INPUT_DIM));

	// Create hidden layer's weight matrices
	// Add weight for bias
	for (int i = 0; i < this->layer_num - 1; i++)
		this->weights.push_back(Matrix(class_num, class_num + 1));

	initialize_data();
	initialize_labels();
	initialize_weights();
}

void NeuralNetwork::initialize_data() {

	for (int i = 0; i < this->points->get_size(); i++) {
		this->data->set_value(this->points->get_x1(i), 0, i);
		this->data->set_value(this->points->get_x2(i), 1, i);
		this->data->set_value(1, 2, i);
	}
}

void NeuralNetwork::initialize_labels() {

	for (int i = 0; i < this->points->get_size(); i++) {
		for (int j = 0; j < this->class_num; j++) {

			if (j == this->points->get_label(i)) {
				this->labels->set_value(1, j, i);
			}
			else {

				if (activation_function == UNIPOLAR_SIGMOID) {
					this->labels->set_value(0, j, i);
				}

				else if (activation_function == BIPOLAR_SIGMOID) {
					this->labels->set_value(-1, j, i);
				}
			}
		}
	}
}

void NeuralNetwork::initialize_weights() {

	for (int i = 0; i < this->weights.size(); i++)
		this->weights.at(i).initialize_matrix();
}

double NeuralNetwork::train() {

	int sample_size = this->points->get_size();
	double cycle_error = 0;

	// Forward and backward propagation
	for (int i = 0; i < this->sample_size; i++) {

		// Get input and label vectors
		vector<Matrix> activations;
		Matrix error;	
		Matrix input_vector = this->data->get_vector(i);
		Matrix label_vector = this->labels->get_vector(i);

		// Forward propagation
		activations.push_back(input_vector);
		for (int j = 0; j < this->layer_num; j++) {

			Matrix output = (this->weights.at(j) * activations.at(j));
	
			// If it's not final layer then add bias
			if (j != layer_num - 1)
				activations.push_back(this->get_activation(output).add_bias());
			else
				activations.push_back(this->get_activation(output));
		}

		// Calculate total error
		cycle_error += (((label_vector - activations.at(this->layer_num)) ^ 2) * (0.5)).vector_sum();

		// Backpropagation
		for (int k = this->layer_num; k > 0;  k--) { 

			if (k == layer_num) {
				
				Matrix output_vector = activations.at(k);
				Matrix derivative = this->get_derivative(output_vector);

				Matrix diff = label_vector - output_vector;
				error = diff.element_wise_multiplication(derivative);
			}
			else {
				
				Matrix activation = activations.at(k);
				Matrix derivative = this->get_derivative(activation);

				error = (this->weights.at(k).T() * error).element_wise_multiplication(derivative).exclude_bias();
			}

			// Calculate gradient of weight matrix
			Matrix activation = activations.at(k - 1).T();

			// Calculate gradient
			// If it's first pass there are no previous gradients
			Matrix gradient;

			if (i == 0) 
				gradient = ((error * activation) * this->learning_constant);
			else
				gradient = ((error * activation) * this->learning_constant) +
					this->gradients[this->layer_num - k] * this->momentum_constant;

			this->gradients[this->layer_num - k] = gradient;
			
			// Update weights
			Matrix new_weight = this->weights.at(k - 1) + gradient;
			this->weights.at(k - 1) = new_weight;
		}
	}
	
	return cycle_error;
}

vector<Matrix> NeuralNetwork::get_weights(){
	return this->weights;
}

Matrix NeuralNetwork::get_activation(Matrix& output) {
	
	Matrix activation(output.get_first_dim(), output.get_second_dim());

	if (this->activation_function == UNIPOLAR_SIGMOID) {

		for (int i = 0; i < output.get_first_dim(); i++) {
			for (int j = 0; j < output.get_second_dim(); j++) {
				double linear_output = output.get_value(i, j);
				double activation_output = 1 / (1 + exp(-linear_output));
				activation.set_value(activation_output, i, j);
			}
		}
	}

	else if (this->activation_function == BIPOLAR_SIGMOID) {

		for (int i = 0; i < output.get_first_dim(); i++) {
			for (int j = 0; j < output.get_second_dim(); j++) {
				double linear_output = output.get_value(i, j);
				double activation_output = 2 / (1 + exp(-linear_output)) - 1;
				activation.set_value(activation_output, i, j);
			}
		}
	}

	else if (this->activation_function == ReLU) {

		for (int i = 0; i < output.get_first_dim(); i++) {
			for (int j = 0; j < output.get_second_dim(); j++) {
				double linear_output = output.get_value(i, j);
				if (linear_output < 0)
					linear_output = -0.01;
				activation.set_value(linear_output, i, j);
			}
		}
	}

	return activation;
}

Matrix NeuralNetwork::get_derivative(Matrix& activation) {
	
	Matrix derivative(activation.get_first_dim(), activation.get_second_dim());

	if (this->activation_function == UNIPOLAR_SIGMOID) {

		for (int i = 0; i < activation.get_first_dim(); i++) {
			for (int j = 0; j < activation.get_second_dim(); j++) {
				
				double value = activation.get_value(i, j);
				double derivative_value = value * (1 - value);
				derivative.set_value(derivative_value, i, j);
			}
		}
	}

	else if (this->activation_function == BIPOLAR_SIGMOID) {

		for (int i = 0; i < activation.get_first_dim(); i++) {
			for (int j = 0; j < activation.get_second_dim(); j++) {

				double value = activation.get_value(i, j);
				double derivative_value = 0.5 * (1 - pow(value, 2));
 				derivative.set_value(derivative_value, i, j);
			}
		}
	}

	return derivative;
}

int NeuralNetwork::get_class_num() {
	return this->class_num;
}

int NeuralNetwork::make_prediction(NNPoint point) {

	Matrix output;
	Matrix input(3, 1);
	int label = 0;

	// Create input vector
	input.set_value(point.get_x1(), 0, 0);
	input.set_value(point.get_x2(), 1, 0);
	input.set_value(1, 2, 0);

	output = input;

	// Forward propagation
	for (int j = 0; j < this->layer_num; j++) {
		output = (this->weights.at(j) * output);
		
		// If it's not final layer then add bias
		if (j != layer_num - 1)
			output = this->get_activation(output).add_bias();
		else
			output = this->get_activation(output);
	}

	double out = output.get_value(0, 0);

	for (int i = 1; i < this->class_num; i++) {
		double temp = output.get_value(i, 0);
		if (out < temp) {
			label = i;
			out = temp;
		}
	}

	return label;
}