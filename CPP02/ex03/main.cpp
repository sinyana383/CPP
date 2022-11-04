#include <iostream>
#include "Point.h"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	const Point a(0.28f,0.38f);
	const Point b(0.84f,3.1f);
	const Point c(4.04f,0.22f);
	const Point p(3.51f,0.46f);


	std::cout << bsp(a, b, c, p) << std::endl; // в треугольнике
	const Point p1(3.51f,0.24f);
	std::cout << bsp(a, b, c, p1) << std::endl;// на треугольнике
	const Point p2(3.51f,0.06f);
	std::cout << bsp(a, b, c, p2) << std::endl;// вне треугольника

	return 0;
}