#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//constructors

Fixed::Fixed()
{
	this->_fixed_point = 0;
}

Fixed::Fixed(const Fixed& name)
{
	*this = name;
}

Fixed::Fixed(const int nbr)
{
	_fixed_point = nbr << _fractional_bits;
}

Fixed::Fixed(const float nbr)
{
	_fixed_point = roundf(nbr * (1 << _fractional_bits));
}

//assign operator

const Fixed& Fixed::operator=(const Fixed& name)
{
	if (this != &name)
		this->_fixed_point = name._fixed_point;
	return *this;
}

//comparison operators

bool Fixed::operator>(const Fixed& name) const
{
	if (this->_fixed_point > name._fixed_point)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& name) const
{
	if (this->_fixed_point < name._fixed_point)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& name) const
{
	if (this->_fixed_point >= name._fixed_point)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& name) const 
{
	if (this->_fixed_point <= name._fixed_point)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& name) const
{
	if (this->_fixed_point == name._fixed_point)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& name) const
{
	if (this->_fixed_point != name._fixed_point)
		return true;
	return false;
}

//arithmetics operators

Fixed	Fixed::operator+(const Fixed& name) const
{
	Fixed var;
	var._fixed_point = this->_fixed_point + name._fixed_point;
	return var;
}

Fixed	Fixed::operator-(const Fixed& name) const
{
	Fixed var;
	var._fixed_point = this->_fixed_point - name._fixed_point;
	return var;
}

Fixed	Fixed::operator*(const Fixed& name) const
{
	Fixed var;
	var._fixed_point = this->_fixed_point * name._fixed_point;
	var._fixed_point = var._fixed_point >> this->_fractional_bits;
	return var;
}

Fixed	Fixed::operator/(const Fixed& name) const
{
	Fixed var;
	float res = (float)this->_fixed_point / (float)name._fixed_point;
	var._fixed_point = roundf(res * (1 << this->_fractional_bits));
	return var;
}

//increment/decrement operators

const Fixed& Fixed::operator++()
{
	++this->_fixed_point;
	return *this;
}
const Fixed Fixed::operator++(int)
{
	Fixed var;
	var._fixed_point = this->_fixed_point++;
	return var;
}
const Fixed& Fixed::operator--()
{
	--this->_fixed_point;
	return *this;
}
const Fixed Fixed::operator--(int)
{
	Fixed var;
	var._fixed_point = this->_fixed_point--;
	return var;
}

//class member functions

int Fixed::toInt(void) const
{
	return (_fixed_point >> _fractional_bits);
}

float Fixed::toFloat(void) const
{
    return ((float)_fixed_point / (1 << _fractional_bits));
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

//destructor

Fixed::~Fixed()
{
}

//function

std::ostream& operator<<(std::ostream& outstream, const Fixed& name)
{
    outstream << name.toFloat();
    return outstream;
}
