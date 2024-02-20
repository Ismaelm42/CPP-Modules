#include "Ice.hpp"

Ice::Ice()
:AMateria("ice")
{

}

Ice::Ice(const Ice& other)
:AMateria("ice")
{
	*this = other;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Ice::~Ice()
{

}

AMateria* Ice::clone() const
{
	AMateria *new_ice = new Ice();
	return new_ice;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
