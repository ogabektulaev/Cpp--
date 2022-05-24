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
    Circle(Point center, double radius);  //constructors: initialization of member variables
    ~Circle() //simple message out from Destructor
    {
        cout << "Destruction of a class instance " << endl;
        cout << "Center: [" << center.getx() << ", " << center.gety() << "], ";
        cout << "Radius: " << radius << endl;
    };

    void info(void);  //Displays center position and radius of the cirlce
};

#endif //__CIRCLE_H__