#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& name);
		Fixed(const int nbr);
		Fixed(const float nbr);
		~Fixed();

		const Fixed&	operator=(const Fixed& name);

		bool operator>(const Fixed& name) const;
		bool operator<(const Fixed& name) const;
		bool operator>=(const Fixed& name) const;
		bool operator<=(const Fixed& name) const;
		bool operator==(const Fixed& name) const;
		bool operator!=(const Fixed& name) const;

		Fixed	operator+(const Fixed& name) const;
		Fixed	operator-(const Fixed& name) const;
		Fixed	operator*(const Fixed& name) const;
		Fixed	operator/(const Fixed& name) const;

		const Fixed&	operator++();
		const Fixed		operator++(int);
		const Fixed&	operator--();
		const Fixed		operator--(int);

		int					toInt(void) const;
		float				toFloat(void) const;

		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& outstream, const Fixed& name);


#endif
