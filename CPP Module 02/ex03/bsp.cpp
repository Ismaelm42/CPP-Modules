#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	get_sign(Point const point, Point const a, Point const b)
{
	return ((point.x - b.x) * (a.y - b.y) - (a.x - b.x) * (point.y - b.y));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed zero;
	bool neg, pos;


	Fixed s1 (get_sign(point, a, b));
	Fixed s2 (get_sign(point, b, c));
	Fixed s3 (get_sign(point, c, a));
	if (s1 == zero || s2 == zero || s3 == zero)
		return false;
	neg = (s1 < zero) || (s2 < zero) || (s3 < zero);
	pos = (s1 > zero) || (s2 > zero) || (s3 > zero);
	if (neg && pos)
		return false;
	return true;
}
