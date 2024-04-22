#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: no expression has been entered" << std::endl;
		return -1;
	}

	std::string arg = "";
	for (int i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		arg = arg + " " + str;
	}

	RPN rpn(arg);
	rpn.print_result();
	return 0;
}
