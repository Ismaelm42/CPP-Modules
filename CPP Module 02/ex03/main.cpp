#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main()
{
	Point a(2, 1);
	Point b(3, 3);
	Point c(4, 1);
	Point point(3, 2);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << point << std::endl;

	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}
