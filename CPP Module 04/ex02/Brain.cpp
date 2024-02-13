#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = other;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
		for(int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}
