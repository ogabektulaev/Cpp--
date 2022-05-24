#ifndef _POINT_H_
#define _POINT_H_

class Point
{
private:
	double x, y;

public:
	Point(double x, double y);
	// ~Point();

	void info();
	double getx();
	double gety();
	void get(double &x, double &y);
};

#endif // _POINT_H_