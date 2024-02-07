#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& f_name);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& f_name);

		void		attack(const std::string& target);
		void		highFivesGuys();
};

#endif
