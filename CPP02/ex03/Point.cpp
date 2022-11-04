#include "Point.h"

Point::Point() : x(0), y(0)
{}
Point::Point(const float x1, const float y1) : x(x1), y(y1)
{}
Point::Point(const Point &p) : x(p.getX()), y(p.getY())
{}
Point &Point::operator=(const Point &p)
{
	// так x и y уже нельзя исправлять, они же const!!!
	if (this == &p) return *this;

	return *this;
}

const Fixed & Point::getX() const
{
	return x;
}
const Fixed & Point::getY() const
{
	return y;
}

Point::~Point()
{}
