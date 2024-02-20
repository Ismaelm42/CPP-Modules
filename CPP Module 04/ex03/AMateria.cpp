#include "AMateria.hpp"
#include <memory>

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const& type)
:type(type)
{

}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	delete this;
	AMateria *new_materia = other.clone();
	return *new_materia;
}

AMateria::~AMateria()
{

}

std::string const& AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

