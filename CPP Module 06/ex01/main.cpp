#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data *ptr = new Data;

	ptr->id = "Hello!";

	std::cout << "*ptr:\t\t" << ptr << std::endl;
	std::cout << "ptr->id:\t" << ptr->id << std::endl << std::endl;
	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "raw:\t\t" << raw << std::endl << std::endl;
	Data *new_ptr = Serializer::deserialize(raw);
	std::cout << "*new_ptr:\t" << new_ptr << std::endl;
	std::cout << "new_ptr->id:\t" << new_ptr->id << std::endl;
	delete ptr;
}
