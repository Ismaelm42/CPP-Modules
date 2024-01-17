#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <cstdlib>


int	main()
{
	std::string	string;
	std::string	n;

	std::cout << "Please, enter a new name to create a zombie horde:" << std::endl;
	std::getline(std::cin, string);
	std::cout << "Please, enter the number of zombies in the horde:" << std::endl;
	std::getline(std::cin, n);

	int N = std::atoi(n.c_str());
	Zombie	*horde = zombieHorde(N, string);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
