#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap diam_1("Dummy"), diam_2;

	diam_1.attack("water");
	diam_1.whoAmI();
	diam_1 = diam_2;
	diam_1.whoAmI();

	return 0;
}
