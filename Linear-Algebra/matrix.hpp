#ifndef MATRIX_HEADER_H
#define MATRIX_HEADER_H

#include <iostream>
#include <cstddef>
#include <memory>

using namespace std;

class Matrix{
	public:
		Matrix();
		Matrix(size_t, size_t);
		Matrix(double**, size_t, size_t);
		Matrix(const Matrix&);
		~Matrix();
		void fill(double) const;
		void fill(double**) const;
		size_t get_row_count() const;
		size_t get_col_count() const; 
		unique_ptr<Matrix> extract_col(size_t);
		unique_ptr<Matrix> extract_row(size_t);
		double dot_product(Matrix& v1, Matrix& v2);
		unique_ptr<Matrix> transpose();
		double get_elem(size_t, size_t);
		void print_mat(string);

	protected:
		double** initialize_mat(size_t, size_t);

	private:
		double** mat;
		size_t row_count;
		size_t col_count;
};
#endif