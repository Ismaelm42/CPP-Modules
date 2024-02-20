#include "Bureaucrat.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{
	Bureaucrat newBureaucrat("Alfred", 155);

	std::cout << newBureaucrat;
	int rand_num = 0;
	for (int i = 0; i < 155; i++)
	{
		if (i == rand_num)
		{
			std::cout << "nº " << i << " " << newBureaucrat;
			rand_num = rand();
			std::cout << "rand num = " << rand_num << std::endl;
		}
		newBureaucrat.increment();
	}
	return 0;
}
