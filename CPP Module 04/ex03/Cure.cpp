#include "Cure.hpp"

Cure::Cure()
:AMateria("cure")
{

}

Cure::Cure(const Cure& other)
:AMateria("cure")
{
	*this = other;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	AMateria *new_cure = new Cure();
	return new_cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

