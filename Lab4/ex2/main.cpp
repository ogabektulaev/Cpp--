#include <iostream>
using namespace std;

#include "Circle.h"
//my IDE can't compile without importing below
#include "Point.cpp"
#include "Circle.cpp"

int main(void){
	Circle c1;
	Circle c2{};

	Point p{10.5, 20.5};
	Circle c3{p, 20.0};
	Circle c4{{20.5, 10.5}, 10.0};

	cout << "c1.info: ";
	c1.info();
	cout << "c2.info: ";
	c2.info();
	cout << "c3.info: ";
	c3.info();
	cout << "c4.info: ";
	c4.info();

	return 0;
}