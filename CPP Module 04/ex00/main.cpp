#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main()
{
	const Animal* meta = new Animal();
	const Animal* pussycat = new Cat();
	const Animal* doggy = new Dog();

	std::cout << std::endl;
	std::cout << "-" << doggy->getType() << std::endl;
	std::cout << "-" << pussycat->getType() << std::endl;
	std::cout << "-" << meta->getType() << std::endl;
	std::cout << std::endl;

	pussycat->makeSound();
	doggy->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete(meta);
	delete(pussycat);
	delete(doggy);

	std::cout << std::endl;

	const WrongAnimal* def_wrong = new WrongAnimal();
	const WrongAnimal* wrongy_the_cat = new WrongCat();

	def_wrong->makeSound();
	wrongy_the_cat->makeSound();
	std::cout << std::endl;
	std::cout << "-" << wrongy_the_cat->getType() << std::endl;
	std::cout << "-" << def_wrong->getType() << std::endl;
	std::cout << std::endl;

	delete(def_wrong);
	delete(wrongy_the_cat);

	return 0;
}
