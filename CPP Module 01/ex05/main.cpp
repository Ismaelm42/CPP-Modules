#include "Harl.hpp"
#include <iostream>
#include <string>

int	main()
{
	Harl harl;
	std::string	buffer;

	std::cout << "Enter a Harl complain type: " << std::endl;
	init:
	std::cin >> buffer;
	if (buffer != "DEBUG" && buffer != "INFO"
	&& buffer != "WARNING" && buffer != "ERROR")
	{
		std::cout << "Complain type doesn't exist. Try again!" << std::endl;
		goto init;
	}
	harl.complain(buffer);
	return 0;
}
