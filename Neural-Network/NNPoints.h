#pragma once

#include "NNPoint.h"
#include <vector>
#include <math.h>

using namespace std;

class NNPoints {

public:

	NNPoints();
	~NNPoints();
	int get_size();
	void add_point(NNPoint point);
	NNPoint get_point(int index);
	double get_x1(int index);
	double get_x2(int index);
	int get_label(int index);
	vector<NNPoint> get_points();
	void normalize_points();
	void calculate_mean();
	void calculate_std();
	void clear_points();
	double convert_to_x1(double x1);
	double convert_to_x2(double x2);

private:

	vector<NNPoint> points;
	double mean_x1;
	double mean_x2;
	double std_x1;
	double std_x2;
};