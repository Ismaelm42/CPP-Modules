#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <exception>

template <class T>
	void easyfind(T& container, int n)
	{
		typename T::iterator it = std::find(container.begin(), container.end(), n);
		if (it != container.end())
			return ;
		throw std::exception();
	}

#endif
