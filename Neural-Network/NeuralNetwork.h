#pragma once

#include <vector>
#include <stdlib.h>
#include <time.h>

#include "NNPoints.h"
#include "Matrix.h"

#define UNIPOLAR_SIGMOID 2
#define BIPOLAR_SIGMOID  3
#define ReLU

class NeuralNetwork {

public:

	NeuralNetwork(NNPoints* points, int activation_function, int class_num,
		int layer_num, double learning_constant, double momentum_constant);
	double train();
	vector<Matrix> get_weights();
	int get_class_num();
	int make_prediction(NNPoint point);

private:

	NNPoints* points;
	std::vector<Matrix> weights;
	Matrix* gradients;
	Matrix* data;
	Matrix* labels;
	int activation_function;
	int class_num;
	int layer_num;
	int sample_size;
	double learning_constant;
	double momentum_constant;

	void initialize_data();
	void initialize_labels();
	void initialize_weights();
	Matrix get_derivative(Matrix& output);
	Matrix get_activation(Matrix& output);
};