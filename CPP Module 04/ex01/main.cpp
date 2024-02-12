#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* doggo = new Dog();
	const Animal* pussycat = new Cat();

	std::cout << std::endl << std::endl << std::endl;

	delete doggo;
	delete pussycat;
	std::cout << std::endl << std::endl << std::endl;

	const Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();

	std::cout << std::endl << std::endl << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << std::endl << std::endl << std::endl;

	Dog dog1;
	Dog dog2;

	dog1 = dog2;

	return 0;
}
