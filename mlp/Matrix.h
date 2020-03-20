#pragma once

#include <exception>
#include <chrono>
#include <random>

#define UNIPOLAR_SIGMOID 2
#define BIPOLAR_SIGMOID  3

class Matrix {
	
	public:

		Matrix();
		Matrix(int first_dim, int second_dim);
		Matrix(const Matrix& other);
		~Matrix();
		void initialize_matrix();
		Matrix operator*(Matrix&);
		Matrix operator*(double scalar);
		Matrix operator+(Matrix&);
		Matrix operator-(Matrix&);
		Matrix operator^(double power);
		void operator=(const Matrix&);
		Matrix element_wise_multiplication(Matrix&);
		Matrix T();
		double vector_sum();
		Matrix add_bias();
		Matrix exclude_bias();
		double get_value(int first_dim, int second_dim);
		Matrix get_vector(int index);
		void set_value(double value, int first_dim, int second_dim);
		double** get_matrix();
		int get_first_dim();
		int get_second_dim();

	private:

		int first_dim;
		int second_dim;
		double** matrix;
};