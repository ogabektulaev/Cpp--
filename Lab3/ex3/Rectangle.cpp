#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
    if ((ul.GetX() > lr.GetX()) || (ul.GetY() > lr.GetY()))
        return false;
    m_upLeft = ul;
    m_lowRight = lr;
    // Identifying rest of the two corners points of rectangle
    m_lowLeft.InitMembers(m_upLeft.GetX(), m_lowRight.GetY());
    m_upRight.InitMembers(m_lowRight.GetX(), m_upLeft.GetY());
    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout << "LeftTop: " << '[' << m_upLeft.GetX() << ", ";
    cout << m_upLeft.GetY() << ']' << endl;
    cout << "LeftDown: " << '[' << m_lowLeft.GetX() << ", ";
    cout << m_lowLeft.GetY() << ']' << endl;

    cout << "RightTop: " << '[' << m_upRight.GetX() << ", ";
    cout << m_upRight.GetY() << ']' << endl;
    cout << "RightBottom: " << '[' << m_lowRight.GetX() << ", ";
    cout << m_lowRight.GetY() << ']' << endl;
}

// Checking the point inside or outside of rectangle
bool Rectangle::IsInside(const Point &point)
{
    if (m_upLeft.GetX() < point.GetX() < m_upRight.GetX() && m_upLeft.GetY() < point.GetY() < m_lowLeft.GetY())
        return true;

    return false;
}