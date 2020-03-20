#include "Matrix.h"

Matrix::Matrix(){}

Matrix::Matrix(int first_dim, int second_dim) {
	this->first_dim = first_dim;
	this->second_dim = second_dim;

	this->matrix = new double*[first_dim];

	for (int i = 0; i < first_dim; i++)
		this->matrix[i] = new double[second_dim];
}

void Matrix::operator=(const Matrix& other) {

	this->first_dim = other.first_dim;
	this->second_dim = other.second_dim;
	this->matrix = new double*[this->first_dim];

	for (int i = 0; i < this->first_dim; i++)
		matrix[i] = new double[this->second_dim];

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
}

// Copy constructor
Matrix::Matrix(const Matrix& other) {
	
	this->first_dim = other.first_dim;
	this->second_dim = other.second_dim;
	this->matrix = new double*[this->first_dim];

	for (int i = 0; i < this->first_dim; i++)
		matrix[i] = new double[this->second_dim];

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {
			this->matrix[i][j] = other.matrix[i][j];
		}
	}

}


Matrix::~Matrix() {
	for (int i = 0; i < this->first_dim; i++)
		delete[] matrix[i];

	delete[] matrix;
}

void Matrix::initialize_matrix() {
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::normal_distribution<double> distribution(0.0, 1.0);

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {
			double weight = distribution(generator);
			this->matrix[i][j] = weight;
		}
	}
}

Matrix Matrix::operator*(Matrix& other) {

	if (this->second_dim != other.first_dim) {
		throw std::exception();
	}

	Matrix result(this->first_dim, other.second_dim);

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < other.second_dim; j++) {
			double mul = 0;
			for (int k = 0; k < this->second_dim; k++) {
				mul += this->get_value(i, k) * other.get_value(k, j);
			}
			result.set_value(mul, i, j);
		}
	}

	return result;
}

Matrix Matrix::operator*(double scalar) {

	Matrix result(this->first_dim, this->second_dim);

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {
			double val = this->get_value(i, j);
			double mul = val * scalar;
			result.set_value(mul, i, j);
		}
	}

	return result;
}


Matrix Matrix::operator+(Matrix& other) {

	if (this->first_dim != other.first_dim ||
		this->second_dim != other.second_dim) {
		throw std::exception();
	}

	Matrix result(this->first_dim, this->second_dim);

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {
			double sum = this->get_value(i, j) + other.get_value(i, j);
			result.set_value(sum, i, j);
		}
	}

	return result;
}

Matrix Matrix::operator-(Matrix& other) {

	if (this->first_dim != other.first_dim ||
		this->second_dim != other.second_dim) {
		throw std::exception();
	}

	Matrix result(this->first_dim, this->second_dim);

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {

			double a = this->get_value(i, j);
			double b = other.get_value(i, j);
			double diff = a-b;
			result.set_value(diff, i, j);
		}
	}

	return result;
}

Matrix Matrix::operator^(double power) {

	Matrix result(this->first_dim, this->second_dim);

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {
			double value = this->matrix[i][j];
			double new_value = pow(value, power);
			result.set_value(new_value, i, j);
		}
	}

	return result;
}

Matrix Matrix::element_wise_multiplication(Matrix& other) {

	if (this->first_dim != other.first_dim ||
		this->second_dim != other.second_dim) {
		throw std::exception();
	}

	Matrix result(this->first_dim, this->second_dim);

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {
			double mul = this->get_value(i, j) * other.get_value(i, j);
			result.set_value(mul, i, j);
		}
	}

	return result;
}

Matrix Matrix::T() {

	Matrix result(this->second_dim, this->first_dim);

	for (int i = 0; i < this->first_dim; i++) {
		for (int j = 0; j < this->second_dim; j++) {
			double value = this->get_value(i, j);
			result.set_value(value, j, i);
		}
	}

	return result;
}

double Matrix::vector_sum() {

	double sum = 0;

	for (int i = 0; i < this->first_dim; i++)
		sum += this->matrix[i][0];

	return sum;
}

Matrix Matrix::add_bias() {

	Matrix new_matrix(this->first_dim + 1, 1);

	for (int i = 0; i < this->first_dim; i++)
		new_matrix.set_value(this->matrix[i][0], i, 0);

	new_matrix.set_value(1, this->first_dim, 0);

	return new_matrix;
}

Matrix Matrix::exclude_bias() {

	Matrix new_matrix(this->first_dim - 1, 1);

	for (int i = 0; i < new_matrix.get_first_dim(); i++) {
		double value = this->matrix[i][0];
		new_matrix.set_value(value, i, 0);
	}

	return new_matrix;
}

void Matrix::set_value(double value, int first_dim, int second_dim) {
	this->matrix[first_dim][second_dim] = value;
}

double Matrix::get_value(int first_dim, int second_dim) {
	return this->matrix[first_dim][second_dim];
}

Matrix Matrix::get_vector(int sample) {

	Matrix vec(this->first_dim, 1);

	for (int i = 0; i < this->first_dim; i++) {
		double val = get_value(i, sample);
		vec.set_value(val, i, 0);
	}

	return vec;
}
double** Matrix::get_matrix() {
	return this->matrix;
}

int Matrix::get_first_dim() {
	return this->first_dim;
}

int Matrix::get_second_dim() {
	return this->second_dim;
}