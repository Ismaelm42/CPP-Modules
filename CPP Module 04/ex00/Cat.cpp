#include "Cat.hpp"
#include <iostream>

Cat::Cat()
:Animal("Cat")
{
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
:Animal("Cat")
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->Animal::_type = other.Animal::_type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound()const
{
	std::cout << "Meow!" << std::endl;
}
