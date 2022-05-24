#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(double x1, double y1) : x(x1), y(y1)
{
}

void Point::info()
{
	cout << "(x,y) = " << x << ", " << y << endl;
}

double Point::getx() const { return x; }
double Point::gety() const { return y; }

void Point::get(double &x1, double &y1)
{
	x1 = x;
	y1 = y;
}
