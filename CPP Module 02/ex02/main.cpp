#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// Fixed x(4.5f);
	// Fixed y(5.5f);
	// std::cout << std::endl << std::endl << std::endl;
	// std::cout << x + y << std::endl;
	// std::cout << x - y << std::endl;
	// std::cout << x * y << std::endl;
	// std::cout << x / y << std::endl;
	// std::cout << x.min(x, y) << std::endl;
	// std::cout << x.max(x, y) << std::endl;

	return 0;
}
