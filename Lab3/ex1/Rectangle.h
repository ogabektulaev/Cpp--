#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"  //for using point type objects in this class

class Rectangle
{
public:
    Point m_upLeft;
    Point m_lowRight;

public:
    bool InitMembers(const Point &ul, const Point &lr);
    void ShowRecInfo() const;
};
#endif // __RECTANGLE_H__