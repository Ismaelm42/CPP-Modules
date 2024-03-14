#include "Bureaucrat.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{
	int range = 155;
	Bureaucrat newBureaucrat("Alfred", range);

	int rand_num = range;
	srand(time(NULL));
	for (int i = 0; i < range; i++)
	{
		if (range - i == rand_num)
		{
			rand_num = rand() % 20 + (newBureaucrat.getGrade() - 20);
			std::cout << newBureaucrat;
		}
		newBureaucrat.increment();
	}
	std::cout << newBureaucrat;
	return 0;
}
