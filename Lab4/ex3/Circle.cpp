#include <iostream>
#include <cmath>
using namespace std;
#include "Circle.h"

Circle::Circle(Point centerPoint = Point{0, 0}, double radiusconst = 0.0) : center(centerPoint), radius(radiusconst){};

void Circle::info()
{
    cout << "Center: [" << center.getx() << ", " << center.gety() << "], ";
    cout << "Radius: " << radius << endl;
}

double Circle::Area() { return M_PI * radius * radius; }
Point Circle::Center() { return center; }
double Circle::Radius() { return radius; }

bool Circle::IsInside(Point point)
{
    double distance = sqrt(pow((point.getx() - center.getx()), 2) + pow((point.gety() - center.gety()), 2));
    // cout << distance;
    if (distance < radius)
        return true;
    return false;
}