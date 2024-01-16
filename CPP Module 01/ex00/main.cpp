#include "Zombie.h"
#include <iostream>

int	main()
{
	std::string	string;

	std::cout << "Please, enter a new name to create a zombie on the stack:" << std::endl;
	std::getline(std::cin, string);
	Zombie stack_zomb(string);
	stack_zomb.announce();

	std::cout << "Please, enter a new name to create a random chump on the stack:" << std::endl;
	std::getline(std::cin, string);
	randomChump(string);

	std::cout << "Please, enter a new name to create a zombie on the heap:" << std::endl;
	std::getline(std::cin, string);
	Zombie *heap_zomb = newZombie(string);
	heap_zomb->announce();
	delete(heap_zomb);
}
