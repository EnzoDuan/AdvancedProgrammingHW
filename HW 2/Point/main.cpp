#include "Point.h"
using namespace std;

int main() {
	double x, y;
	/* A does not use constructor function to initialize. */
	Point *A = new Point();
	/* p uses constructor function to initialize. */
	Point *p = new Point(2.0, 3.0);
	x = 1.0, y = 2.0;
	A->set_position(x, y);
	cout << "Point A's polar radius is: " << A->r() << endl;
	cout << "Point A's polar angle is: " << A->theta() << endl;
	cout << "Point A's distance to point p is: " << A->distance(*p) << endl;
	cout << "Point A's relative coordinates to point p is: ";
	A->relative(*p).print();
	if (A->is_above_left(*p))
		cout << "Point A is in the upper left of point p" << endl;
	else
		cout << "Point A is not in the upper left of point p" << endl;

	return 0;
}