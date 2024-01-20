#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		std::string	_human_name;
		Weapon		*_weapon_type;
	public:
		HumanB(std::string human_name);
		~HumanB();
		void	setWeapon(Weapon &weapon_type);
		void	attack();
};

#endif
