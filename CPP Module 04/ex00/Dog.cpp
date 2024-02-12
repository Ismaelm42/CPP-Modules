#include "Dog.hpp"
#include <iostream>

Dog::Dog()
:Animal("Dog")
{
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
:Animal("Dog")
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->Animal::_type = other.Animal::_type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound()const
{
	std::cout << "Woof Woof!" << std::endl;
}
