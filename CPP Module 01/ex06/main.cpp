#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	Harl harl;
	std::string buffer;

	for (int i = 1; i < argc; i++)
		buffer.append(argv[i]);
	if (buffer != "")
		harl.complain(buffer);
	return 0;
}
