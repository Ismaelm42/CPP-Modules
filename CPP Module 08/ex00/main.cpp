#include "easyfind.hpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int array[5] = {1,2,3,4,5};
		std::vector<int> vector_container(array, array + sizeof(array) / sizeof(int));
		std::list<int> list_container(array, array + sizeof(array) / sizeof(int));
		try
		{
			::easyfind(vector_container, std::atoi(argv[1]));
		}
		catch(const std::exception& e)
		{
			std::cerr << "Can't find the number in vector container" << std::endl;
		}
		try
		{
			::easyfind(list_container, std::atoi(argv[1]));
		}
		catch(const std::exception& e)
		{
			std::cerr << "Can't find the number in list container" << std::endl;
		}
	}
}
