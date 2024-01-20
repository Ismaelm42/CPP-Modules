#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		std::string 	_human_name;
		Weapon			&_weapon_type;
	public:
		HumanA(std::string human_name, Weapon &weapon_type);
		~HumanA();
		void	attack();
};

#endif
