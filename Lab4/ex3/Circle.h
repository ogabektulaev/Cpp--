#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <iostream>
using namespace std;

#include "Point.h"

class Circle
{
private:
    Point center;
    double radius;

public:
    Circle(Point center, double radius);
    ~Circle()
    {
        cout << "Destruction of a class instance " << endl;
        cout << "Center: [" << center.getx() << ", " << center.gety() << "], ";
        cout << "Radius: " << radius << endl;
    };

    void info(void);

    double Area(void);
    Point Center(void);
    double Radius(void);
    bool IsInside(Point);
};

#endif //__CIRCLE_H__