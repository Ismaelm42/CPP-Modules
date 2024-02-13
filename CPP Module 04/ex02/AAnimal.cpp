#include "AAnimal.hpp"
#include "Dog.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
:_type(type)
{
	std::cout << "AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return _type;
}
