#include <iostream>
using namespace std;
#include "Circle.h"

Circle::Circle(Point centerPoint = Point{0, 0}, double radiusconst = 0) : center(centerPoint), radius(radiusconst){}; //initialization of member variables

void Circle::info()  //Displays center position and raidus of the cirlce
{
    cout << "Center: [" << center.getx() << ", " << center.gety() << "], ";
    cout << "Radius: " << radius << endl;
}
