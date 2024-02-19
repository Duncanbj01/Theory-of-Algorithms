#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#ifndef POINT_H_
#define POINT_H_

class Point {

public:

	double x, y;

	Point() {
		x = y = 0;
	}

	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	const double distance(Point *arg) {
		double diffX = arg->x - x;
		double diffY = arg->y - y;
		double dist = sqrt(diffX * diffX + diffY * diffY);
		return dist;
	}

	string toString() {
		string stringRep = "(" + to_string(x) + "," + to_string(y) + ")";
		return stringRep;
	}
};

#endif /* POINT_H_ */
