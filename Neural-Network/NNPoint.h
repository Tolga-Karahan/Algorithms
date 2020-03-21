#pragma once

#define INPUT_DIM 3 

class NNPoint {

public:

	NNPoint(double x1, double x2, int class_label);
	double get_x1();
	void set_x1(double x1);
	double get_x2();
	void set_x2(double x2);
	int get_class_label();
	void set_label(int label);
	int get_label();

private:

	double x1;
	double x2;
	int class_label;
};