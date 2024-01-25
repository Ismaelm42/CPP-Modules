#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& name);
		const Fixed& operator=(const Fixed& name);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
};

#endif
