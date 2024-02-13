#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type)
:_type(type)
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::makeSound()const
{
	
}

std::string Animal::getType() const
{
	return _type;
}
