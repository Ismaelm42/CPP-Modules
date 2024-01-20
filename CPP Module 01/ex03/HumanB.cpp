#include "HumanB.hpp"

HumanB::HumanB(std::string human_name)
	:_human_name(human_name)
{
	this->_weapon_type = NULL;
}

void	HumanB::setWeapon(Weapon &weapon_type)
{
	this->_weapon_type = &weapon_type;
}

void	HumanB::attack()
{
	if (this->_weapon_type == NULL)
	{
		Weapon fists;
		this->_weapon_type = &fists;
		std::cout << this->_human_name << " attacks with their " << this->_weapon_type->getType() << std::endl;
		this->_weapon_type = NULL;
	}
	else
		std::cout << this->_human_name << " attacks with their " << this->_weapon_type->getType() << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB <" << this->_human_name << "> has been destroyed" << std::endl;
}
