#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: no file as argument." << std::endl;
		return -1;
	}
	try
	{
		BitcoinExchange btn(argv[1]);
		btn.get_data();
	}
	catch(const char * &e)
	{
		std::cerr << e << std::endl;
		return -1;
	}
	return 0;
}

