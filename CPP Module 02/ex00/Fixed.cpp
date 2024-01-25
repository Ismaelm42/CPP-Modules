#include "Fixed.hpp"
#include <iostream>

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

const Fixed&	Fixed::operator=(const Fixed& name)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &name)
		this->_fixed_point = name.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Para interpretar el número decimal representado por el binario 1011 en un sistema de 4 bits con complemento a 2,
// siendo el primer bit el bit de signo negativo, seguimos los siguientes pasos:

//     Identificar el Bit de Signo:
//         El primer bit en 1011 es 1, indicando que el número es negativo.

//     Calcular el Valor Absoluto:
//         Invertimos los bits (complemento a 1): 0100.
//         Sumamos 1 al resultado del paso anterior (complemento a 2): 0101.
//         En binario, 0101 es igual a 5 en decimal.

//     Aplicar el Signo:
//         Dado que el bit de signo es 1 (indicando negativo), multiplicamos el valor absoluto por -1.

// Por lo tanto, el número decimal representado por 1011 en complemento a 2 es -5.
// Nuevamente, lamento la confusión en mi respuesta anterior y agradezco tu paciencia.
