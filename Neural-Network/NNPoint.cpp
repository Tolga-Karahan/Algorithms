#include "NNPoint.h"

NNPoint::NNPoint(double x1, double x2, int class_label) {
	this->x1 = x1;
	this->x2 = x2;
	this->class_label = class_label;
}

double NNPoint::get_x1() {
	return x1;
}

void NNPoint::set_x1(double x1) {
	this->x1 = x1;
}

double NNPoint::get_x2() {
	return x2;
}

void NNPoint::set_x2(double x2) {
	this->x2 = x2;
}

int NNPoint::get_class_label() {
	return class_label;
}

int NNPoint::get_label() {
	return class_label;
}

void NNPoint::set_label(int label) {
	this->class_label = label;
}