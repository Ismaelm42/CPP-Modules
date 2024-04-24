#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <deque>
#include <iterator>
#include <iomanip>
#include <ctime>
#include <sys/time.h>
#define CHAR_ERROR "Error: Invalid input. Only positive numbers allowed"
#define LEN_ERROR "Error: Invalid input. Number exceeds max int"

class PmergeMe
{	
	private:
		PmergeMe();
		std::string _arg;
		std::vector<int> _vector;
		std::deque<int> _deque;

	public:
		PmergeMe(std::string arg);
		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();

		std::vector<int> check_input();
		void vector_init();
		void deque_init();
		void vector_merge_sort(std::vector<int>& vector);
		void vector_merge(std::vector<int>& v, std::vector<int>& vLeft, std::vector<int>& vRight);
		void deque_merge(std::deque<int>& l, std::deque<int>& lLeft, std::deque<int>& lRight);
		void deque_merge_sort(std::deque<int>& l);
		template <class Container>
		void output(const std::string& label, Container& c)
		{
			std::cout << label;
			for (typename Container::iterator it = c.begin(); it != c.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
		void display_timer(struct timeval v1, struct timeval v2, struct timeval d1, struct timeval d2);
		void sort();
};

#endif
