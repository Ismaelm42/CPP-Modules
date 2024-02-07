#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	FragTrap frag_1, frag_2("Julie");
	
	frag_1.attack("nothing");
	frag_2.highFivesGuys();

	FragTrap frag_3(frag_1);
	frag_3.attack("dummy");
	frag_2 = frag_3;
	
	return 0;
}
