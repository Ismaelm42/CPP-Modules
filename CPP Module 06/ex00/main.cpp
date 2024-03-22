#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{	
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "invalid number of arguments" << std::endl;
}
