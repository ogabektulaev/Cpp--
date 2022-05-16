#include <iostream>
using namespace std;

#include "Rectangle.h"
// #include "Rectangle.cpp"
// #include "Point.cpp"



int main()
{
  Point pos1; //creating Point type of object
  if (!pos1.InitMembers(-2, 4))   //using Point class method
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

  return 0;
}