#include "HumanA.hpp"

HumanA::HumanA(std::string human_name, Weapon& weapon_type)
	:_human_name(human_name), _weapon_type(weapon_type)
{

}

void	HumanA::attack()
{
	std::cout << this->_human_name << " attacks with their " << this->_weapon_type.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA <" << this->_human_name << "> has been destroyed" << std::endl;
}
