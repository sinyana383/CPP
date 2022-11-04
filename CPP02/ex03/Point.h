#ifndef CPP02_POINT_H
#define CPP02_POINT_H
#include "Fixed.h"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float x1, const float y1);
	Point(const Point &p);
	Point& operator=(const Point& p);
	~Point();

	const Fixed & getX() const;
	const Fixed & getY() const;
};


#endif //CPP02_POINT_H
