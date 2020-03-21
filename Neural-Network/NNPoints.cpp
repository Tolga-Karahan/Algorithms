#include "NNPoints.h"

NNPoints::NNPoints() {}

int NNPoints::get_size() {
	return this->points.size();
}

NNPoints::~NNPoints() {
	this->points.clear();
}

void NNPoints::add_point(NNPoint point) {
	this->points.push_back(point);
}

NNPoint NNPoints::get_point(int index) {
	return this->points.at(index);
}

double NNPoints::get_x1(int index) {
	return this->points.at(index).get_x1();
}

double NNPoints::get_x2(int index) {
	return this->points.at(index).get_x2();
}

int NNPoints::get_label(int index) {
	return this->points.at(index).get_class_label();
}

vector<NNPoint> NNPoints::get_points() {
	return this->points;
}

void NNPoints::normalize_points() {

	calculate_mean();
	calculate_std();

	for (int i = 0; i < this->points.size(); i++) {

		double x1 = this->points.at(i).get_x1();
		double x2 = this->points.at(i).get_x2();

		x1 = (x1 - this->mean_x1) / this->std_x1;
		x2 = (x2 - this->mean_x2) / this->std_x2;

		this->points.at(i).set_x1(x1);
		this->points.at(i).set_x2(x2);
	}
}

void NNPoints::clear_points() {
	this->points.clear();
}

void NNPoints::calculate_mean() {

	double sum_x1 = 0;
	double sum_x2 = 0;

	for (int i = 0; i < this->points.size(); i++) {

		sum_x1 += this->points.at(i).get_x1();
		sum_x2 += this->points.at(i).get_x2();

	}

	this->mean_x1 = sum_x1 / this->points.size();
	this->mean_x2 = sum_x2 / this->points.size();
}

void NNPoints::calculate_std() {

	double std_x1 = 0;
	double std_x2 = 0;

	for (int i = 0; i < this->points.size(); i++) {

		std_x1 += pow((this->points.at(i).get_x1() - this->mean_x1), 2);
		std_x2 += pow((this->points.at(i).get_x2() - this->mean_x2), 2);
	}

	this->std_x1 = sqrt(std_x1 / (this->points.size() - 1));
	this->std_x2 = sqrt(std_x2 / (this->points.size() - 1));
}

double NNPoints::convert_to_x1(double x1) {
	return x1 * this->std_x1 + this->mean_x1;
}

double NNPoints::convert_to_x2(double x2) {
	return x2 * this->std_x2 + this->mean_x2;
}