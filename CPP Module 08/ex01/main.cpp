#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(-1);
		sp.addNumber(-3);
		sp.addNumber(25);
		sp.addNumber(9);
		sp.addNumber(56);

		Span new_sp(sp);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		new_sp.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// int main()
// {
// 	int arr[500];
// 	srand(time(NULL));
// 	for (int i = 0; i < 500; i++)
// 		arr[i] = rand();
	
// 	Span sp(arr, arr + 500);
// 	for (int i = 0; i < 500; i++)
// 	{
// 		if (arr[i] != sp.array[i])
// 			std::cout << "it doesnt work!" << std::endl;
// 	}

// 		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
// 		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
// 	try
// 	{
// 		sp.addNumber(6);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// }

// int main()
// {
// 	int array[10] = {-2000, -1, -5, -15, -30, -60, -100, -200, -1000, -400};
// 	std::list<int> list(array, array + 10);

// 	Span sp(list.begin(), list.end());
// 	std::list<int>::iterator it = list.begin();
// 	for (int i = 0; i < 10; i++)
// 	{
// 		if (*it != sp.array[i])
// 			std::cout << "it doesnt work!" << std::endl;
// 		it++;
// 	}

// 		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
// 		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

// 	try
// 	{
// 		sp.addNumber(6);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// }

