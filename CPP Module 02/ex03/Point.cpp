#include "Fixed.hpp"
#include "Point.hpp"

Point::Point()
:_x(), _y(), x(_x), y(_y)
{
}

Point::Point(float x, float y)
:_x(x), _y(y), x(_x), y(_y)
{
}

Point::Point(const Point& p)
:_x(p._x), _y(p._y), x(_x), y(_y)
{

}

Point& Point::operator=(const Point& p)
{
	if (this != &p)
	{
		(Fixed)this->_x = p._x;
		(Fixed)this->_y = p._y;
	}
	return *this;
}

Point::~Point()
{
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}
