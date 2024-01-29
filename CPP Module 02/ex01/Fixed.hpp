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
		const Fixed& operator=(const Fixed& name);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& outstream, const Fixed& name);


#endif
