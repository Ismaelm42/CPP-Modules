#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap def, c_trap_1("Clappy"), c_trap_2("Trappy");

	c_trap_1.attack("Trappy");
	c_trap_1.takeDamage(15);
	c_trap_1.beRepaired(0);
	c_trap_1.attack("Trappy");
	c_trap_1.takeDamage(15);

	c_trap_2.beRepaired(10);
	c_trap_1 = c_trap_2;
	c_trap_1.takeDamage(0);

	return 0;
}
