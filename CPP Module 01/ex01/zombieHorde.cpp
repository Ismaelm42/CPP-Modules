#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*horde =  new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return horde;
}

