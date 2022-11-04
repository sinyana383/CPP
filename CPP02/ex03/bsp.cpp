#include "Point.h"

float getArea ( Point const p0, Point const p1, Point const p2 )
{
	// 1/2 * (x0(y1 - y2) + x1(y2-y0) + x2(y0-y1))
	// x012 и y012 - точки вершин 012
	float area;

	// toFloat добавлен тк точность лучше
	area = (  p1.getX().toFloat() * ( p2.getY()  - p0.getY()  ).toFloat() +
			 p0.getX().toFloat() * ( p1.getY()  - p2.getY()  ).toFloat() +
			 p2.getX().toFloat() * ( p0.getY()  - p1.getY()  ).toFloat()
			) / 2;
	if (area < 0)
		return (area * -1);
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	/*
	 точка внутри треугольника делит это треугольник на три части
	 зная координаты всех точек вычисляем все эти части и складываем их
	 если сумма равна площади треугольника - точка в треугольнике
	*/

	float area0, area1, area2;
	float bigArea;

	area0 = getArea(point, a, b);
	area1 = getArea(point, a, c);
	area2 = getArea(point, c, b);

	if (area0 == 0 || area1 == 0 || area2 == 0)
		return false;
	bigArea = getArea(a, b, c);
	if (area0 + area1 + area2 == bigArea)
		return true;
	return false;
}