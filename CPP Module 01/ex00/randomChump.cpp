#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	rand_chump(name);
	rand_chump.announce();
}
