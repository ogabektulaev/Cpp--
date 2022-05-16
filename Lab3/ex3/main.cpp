#include <iostream>
#include "Rectangle.h"
#include "Rectangle.cpp"
#include "Point.cpp"
using namespace std;

int main()
{
  Point pos1;
  if (!pos1.InitMembers(-2, 4))
    cout << "pos1-1: Failure of Init" << endl;
  if (!pos1.InitMembers(2, 4))
    cout << "pos1-2: Failure of Init" << endl;

  Point pos2;
  if (!pos2.InitMembers(5, 9))
    cout << "pos2: Failure of Init" << endl;

  Rectangle rec;
  if (!rec.InitMembers(pos2, pos1))
    cout << "rec-1: Failure of Init" << endl;

  if (!rec.InitMembers(pos1, pos2))
    cout << "rec-2: Failure of Init" << endl;

  rec.ShowRecInfo();

  // Checking the point inside or outside of rectangle
  Point pos3;
  pos3.InitMembers(3, 6);
  cout << "pos3: [" << pos3.GetX() << ", " << pos3.GetY() << "]" << endl;
  if (rec.IsInside(pos3))
    cout << "The pos3 is inside the rectangle." << endl;
  else
    cout << "The pos3 is outside the rectangle." << endl;

  return 0;
}