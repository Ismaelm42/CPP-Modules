#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap
{
	private:

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& s_name);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& s_name);

		void		guardGate();
		void		attack(const std::string& target);
};

#endif
