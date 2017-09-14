#pragma once
#include <cmath>
#include <iostream>
/* Copyright:151220023 */

class Point {
private:
	double _x, _y;
	const double Pi = 3.1415926;
public:
	Point() { _x = 0; _y = 0; }
	Point(double x, double y) { _x = x; _y = y; }

	/*  calculate polar radius  */
	double r() {
		return sqrt(_x*_x + _y*_y);
	}
	/* calculate polar angle */
	double theta() {
		return 180 / Pi * atan(_y / _x);
	}
	/* calculate the distance to point P */
	double distance(const Point& p) {
		return sqrt((_x - p._x)*(_x - p._x) + (_y - p._y)*(_y - p._y));
	}
	/* calculate the relative coordinates to point p,
	   and point p is original point. */
	Point relative(const Point& p) {
		double xAns = _x - p._x, 
			   yAns = _y - p._y;
		return Point(xAns, yAns);
	}
	/* To estimate whether this point is in the upper left of point p. */
	bool is_above_left(const Point& p) {
		return ((_x < p._x) && (_y > p._y));
	}
	/* If not use the constructor function to initialize x and y, use this function to set x and y. */
	void set_position(double x, double y) {
		_x = x; _y = y;
	}
	/* Print point's coordinates */
	void print() {
		std::cout << "(" << _x << "," << _y << ")" << std::endl;
	}
};
