#include "Weapon.hpp"

Weapon::Weapon()
{
	this->setType("bare hands");
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
}

const std::string& Weapon::getType()
{
	return this->_type;
}

void Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}

Weapon::~Weapon()
{
	std::cout << "Weapon <" << this->_type << "> has been destroyed" << std::endl;
}
