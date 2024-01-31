#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
#include <iostream>

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		Point();
		Point(float x, float y);
		Point(const Point& p);
		~Point();

		Fixed	x;
		Fixed	y;

		Point& operator=(const Point& p);
};

std::ostream& operator<<(std::ostream& out, const Point& p);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
