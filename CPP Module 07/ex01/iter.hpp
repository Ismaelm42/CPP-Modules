#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <class T>
	void print(T& t)
	{
		std::cout << t << std::endl;
	}
template <class T>
	void iter(T* ptr, int length, void (*function)(T&))
	{
		if (ptr != NULL && *function != NULL)
			for (int i = 0; i < length; i++)
				function(ptr[i]);
	}

#endif
