#ifndef T_HPP
#define T_HPP
#include <iostream>

template <class T>
	void swap(T& a, T& b)
	{
		T s = a;
		a = b;
		b = s;
	}
template <class T>
	T& min(T& a, T& b)
	{
		return ((a < b)? a : b);
	}
template <class T>
	T& max(T& a, T& b)
	{
		return ((a > b)? a : b);
	}

#endif
