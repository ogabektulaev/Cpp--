#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include "Point.h"

class Rectangle
{
public:
    Point m_upLeft;
    Point m_lowRight;
    Point m_lowLeft;
    Point m_upRight;

public:
    bool InitMembers(const Point &ul, const Point &lr);
    void ShowRecInfo() const;
    bool IsInside(const Point &point);
};
#endif // __RECTANGLE_H__