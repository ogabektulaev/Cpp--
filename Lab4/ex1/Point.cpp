#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(double x1, double y1) : x(x1), y(y1)
{
}

void Point::info()  //displays the position of x, y
{
	cout << "(x,y) = " << x << ", " << y << endl;
}

double Point::getx(){return x;}  //interface function to get x position
double Point::gety(){return y;} //interface function to get y position

void Point::get(double &x1, double &y1) //interface function to get x, y position
{
	x1 = x;
	y1 = y;
}
