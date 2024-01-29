#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

Fixed::Fixed(const Fixed& name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = name;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point = nbr << _fractional_bits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point = roundf(nbr * (1 << _fractional_bits));
}

const Fixed& Fixed::operator=(const Fixed& name)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &name)
		this->_fixed_point = name.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

int		Fixed::getRawBits(void) const
{
	return this->_fixed_point;
}

int		Fixed::toInt(void) const
{
	   return (_fixed_point >> _fractional_bits);
}

float	Fixed::toFloat(void) const
{
    return ((float)_fixed_point / (1 << _fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& outstream, const Fixed& name)
{
    outstream << name.toFloat();
    return outstream;
}
