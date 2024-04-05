#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <stack>

template <class T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator iterator;
		MutantStack(): std::stack<T>()
		{

		}
		MutantStack(const MutantStack& rhs): std::stack<T>(rhs)
		{

		}
		MutantStack& operator=(const MutantStack& rhs)
		{
			std::stack<T>::operator=(rhs);
			return *this;
		}
		virtual ~MutantStack()
		{

		}
		typename std::deque<T>::iterator begin()
		{
			return this->c.begin();
		}
		typename std::deque<T>::iterator end()
		{
			return this->c.end();
		}
};

#endif
