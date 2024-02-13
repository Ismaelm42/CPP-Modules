#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog()
:AAnimal("Dog")
{
	std::cout << "Dog Default Constructor called" << std::endl;
	this->_dog_brain = new Brain();
}

Dog::Dog(const Dog& other)
:AAnimal("Dog")
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->AAnimal::_type = other.AAnimal::_type;
		delete (this->_dog_brain);
		this->_dog_brain = new Brain(*other._dog_brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete (this->_dog_brain);
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound()const
{
	std::cout << "Woof Woof!" << std::endl;
}
