#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	// const AAnimal* test = new AAnimal();
	const AAnimal* test = new Dog();
	const AAnimal* test = new Cat();

	return 0;
}
