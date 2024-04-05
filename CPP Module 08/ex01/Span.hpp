#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <exception>

class Span
{
	private:
		std::vector <int> array;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& rhs);
		Span(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		Span(std::list<int>::iterator begin, std::list<int>::iterator end);
		Span(int* begin, int* end);
		Span& operator=(const Span& rhs);
		~Span();

		void addNumber(int nbr);
		int shortestSpan();
		int longestSpan();

		class NoMoreElementsCanBeAdded: public std::exception
		{
			public:
				const char* what()const throw();
		};
		class NotEnoughNumbersStored: public std::exception
		{
			public:
				const char* what()const throw();
		};
};

#endif
