#ifndef DIAMONDTRAPP_HPP
#define DIAMONDTRAPP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string		_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& d_name);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& d_name);

		void	attack(const std::string& target);
		void	whoAmI();
};

#endif
