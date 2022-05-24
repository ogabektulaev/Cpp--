#include <iostream>
using namespace std;

#include "Circle.h"
#include "Point.cpp"
#include "Circle.cpp"

int main(void)
{
	Circle c1;  //c1 and c2 get default class values
	Circle c2{};
	Point p{10.5, 20.5};
	Circle c3{p, 20.0};
	Circle c4{Point{20.5, 10.5}, 10.0};

	cout << "c1.info: ";
	c1.info();
	cout << "c2.info: ";
	c2.info();
	cout << "c3.info: ";
	c3.info();
	cout << "c4.info: ";
	c4.info();

	cout << "\nArea of c3: " << c3.Area() << endl;
	const Point &cent = c3.Center();
	cout << "Center of c3: ";
	cout << "[" << cent.getx() << ", " << cent.gety()
		 << "]\n";
	cout << "Radius of c3: " << c3.Radius() << endl;
	cout << "IsInside: " << c4.IsInside(Point{25.0, 8.0})
		 << endl
		 << endl;
	return 0;
}