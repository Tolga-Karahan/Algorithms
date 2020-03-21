#include "matrix.hpp"

Matrix::Matrix(){
	// Create 10 by 10 matrix with zeroes
	this->row_count = 10;
	this->col_count = 10;
	this->mat = initialize_mat(10, 10);
	fill(0.0);
}

Matrix::~Matrix(){
	for(int i = 0; i < row_count; i++)
		delete mat[i];

	delete mat;
}

Matrix::Matrix(size_t first_dim, size_t second_dim){
	// Create a matrix with dimension specified by the user
	this->row_count = first_dim;
	this->col_count = second_dim;
	this->mat = initialize_mat(first_dim, second_dim);
	fill(0.0);
}

Matrix::Matrix(double** data, size_t first_dim, size_t second_dim){
	this->row_count = first_dim;
	this->col_count = second_dim;
	this->mat = initialize_mat(first_dim, second_dim);
	fill(data);
}

Matrix::Matrix(const Matrix& other){
	this->mat = initialize_mat(other.get_row_count(), other.get_col_count());
	fill(other.mat);
}

double** Matrix::initialize_mat(size_t first_dim, size_t second_dim){
	double** new_mat = new double*[first_dim];

	for(int i = 0; i < first_dim; i++)
		new_mat[i] = new double[second_dim];

	return new_mat;
}

void Matrix::fill(double value) const{
	for(int i = 0; i < row_count; i++)
		for(int j = 0; j < col_count; j++)
			mat[i][j] = value;
}

void Matrix::fill(double** data) const{
	for(int i = 0; i < row_count; i++)
		for(int j = 0; j < col_count; j++)
			mat[i][j] = data[i][j]; 
}

size_t Matrix::get_row_count() const{
	return row_count;
}

size_t Matrix::get_col_count() const{
	return col_count;
}

unique_ptr<Matrix> Matrix::extract_row(size_t row_num){
	double** row_data = new double*[1];
	row_data[0] = new double[col_count];

	for(int i = 0; i < col_count; i++)
		row_data[0][i] = mat[row_num][i];

	unique_ptr<Matrix> row(new Matrix(row_data, (size_t)1, col_count));
	delete row_data;
	return move(row);
}

unique_ptr<Matrix> Matrix::extract_col(size_t col_num){
	double** col_data = new double*[1];
	col_data[0] = new double[row_count];

	for(int i = 0; i < row_count; i++)
		col_data[0][i] = mat[i][col_num];

	unique_ptr<Matrix> col(new Matrix(col_data, row_count, (size_t)1));
	delete col_data;
	return move(col);
}

double Matrix::dot_product(Matrix& v1, Matrix& v2){
	if (v1.get_row_count() != 1 or v2.get_col_count() != 1 or
	    v1.get_col_count() != v2.get_row_count()){
		cerr << "Wrong dimensions for vector!" << endl;
		return -1;
	}

	double product = 0;

	for(int i = 0; i < v1.get_col_count(); i++)
		product += v1.mat[0][i] * v2.mat[i][0];

	return product;
}

unique_ptr<Matrix> Matrix::transpose(){
	double** transposed_mat = initialize_mat(col_count, row_count);

	for (int i = 0; i < col_count; i++){
		for(int j = 0; j < row_count; j++){
				transposed_mat[i][j] = mat[j][i];
		}
	}

	unique_ptr<Matrix> t_mat(new Matrix(transposed_mat, col_count, row_count));
	delete transposed_mat;
	return move(t_mat);
}

double Matrix::get_elem(size_t row, size_t col){
	return mat[row][col];
}

void Matrix::print_mat(string header=""){
	cout << header << endl;
	for (int i = 0; i < row_count; i++){
		for(int j = 0; j < col_count; j++){
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
