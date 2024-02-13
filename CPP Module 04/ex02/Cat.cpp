#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat()
:AAnimal("Cat")
{
	std::cout << "Cat Default Constructor called" << std::endl;
	this->_cat_brain = new Brain();
}

Cat::Cat(const Cat& other)
:AAnimal("Cat")
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->AAnimal::_type = other.AAnimal::_type;
		delete (this->_cat_brain);
		this->_cat_brain = new Brain(*other._cat_brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete (this->_cat_brain);
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound()const
{
	std::cout << "Meow!" << std::endl;
}
