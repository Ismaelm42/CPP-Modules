#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scav_1, scav_2("Rosetta"), scav_3("Stone");

	scav_1.attack("nothing");
	scav_3.attack("nothing");
	scav_1.guardGate();
	scav_2.guardGate();
	std::cout << std::endl;

	ScavTrap new_scav(scav_3);
	scav_1 = scav_2;

	return 0;
}
