#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(std::string arg)
:_arg(arg)
{

}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs)
	{
		_arg = rhs._arg;
		_vector = rhs._vector;
		_deque = rhs._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{

}

std::vector<int> PmergeMe::check_input()
{
	std::vector<int> input;

	for (int i = 0; _arg[i] != 0; i++)
	{
		if (_arg[i] == ' ')
			continue ;
		else
		{
			int len = 0;
			for (; _arg[i] >= '0' && _arg[i] <= '9'; i++)
				len++;
			if (_arg[i] != ' ' && _arg[i] != 0)
				throw CHAR_ERROR;
			long nbr = std::atol((_arg.substr(i - len, len)).c_str());
			if (nbr > std::numeric_limits<int>::max())
				throw LEN_ERROR;
			input.push_back(nbr);
			if (_arg[i] == 0)
				break ;
		}
	}
	return input;
}

void PmergeMe::vector_init()
{
	for (int i = 0; _arg[i] != 0; i++)
	{
		if (_arg[i] == ' ')
			continue ;
		else
		{
			int len = 0;
			for (; _arg[i] >= '0' && _arg[i] <= '9'; i++)
				len++;
			long nbr = std::atol((_arg.substr(i - len, len)).c_str());
			_vector.push_back(nbr);
			if (_arg[i] == 0)
				break ;
		}
	}
}

void PmergeMe::deque_init()
{
	for (int i = 0; _arg[i] != 0; i++)
	{
		if (_arg[i] == ' ')
			continue ;
		else
		{
			int len = 0;
			for (; _arg[i] >= '0' && _arg[i] <= '9'; i++)
				len++;
			long nbr = std::atol((_arg.substr(i - len, len)).c_str());
			_deque.push_back(nbr);
			if (_arg[i] == 0)
				break ;
		}
	}
}

void PmergeMe::vector_merge(std::vector<int>& v, std::vector<int>& vLeft, std::vector<int>& vRight)
{
	std::vector<int>::iterator it = v.begin(), itLeft = vLeft.begin(), itRight = vRight.begin();

	while (itLeft != vLeft.end() && itRight != vRight.end())
	{
		if (*itLeft < *itRight)
			*it = *itLeft, itLeft++;
		else
			*it = *itRight, itRight++;
		it++;
	}
	for (;itLeft != vLeft.end(); it++, itLeft++)
		*it = *itLeft;
	for (;itRight != vRight.end(); it++, itRight++)
		*it = *itRight;
}

void PmergeMe::vector_merge_sort(std::vector<int>& v)
{
	int length = v.size();
	if (length <= 1)
		return ;

	int mid = length / 2;
	std::vector<int> vLeft (v.begin(), v.begin() + mid);
	std::vector<int> vRight (v.begin() + mid, v.end());

	vector_merge_sort(vLeft);
	vector_merge_sort(vRight);
	vector_merge(v, vLeft, vRight);
}

void PmergeMe::deque_merge(std::deque<int>& d, std::deque<int>& dLeft, std::deque<int>& dRight)
{
	std::deque<int>::iterator it = d.begin(), itLeft = dLeft.begin(), itRight = dRight.begin();

	while (itLeft != dLeft.end() && itRight != dRight.end())
	{
		if (*itLeft < *itRight)
			*it = *itLeft, itLeft++;
		else
			*it = *itRight, itRight++;
		it++;
	}
	for (;itLeft != dLeft.end(); it++, itLeft++)
		*it = *itLeft;
	for (;itRight != dRight.end(); it++, itRight++)
		*it = *itRight;
}

void PmergeMe::deque_merge_sort(std::deque<int>& d)
{
	int length = d.size();
	if (length <= 1)
		return ;

	int mid = length / 2;
	std::deque<int> dLeft (d.begin(), d.begin() + mid);
	std::deque<int> dRight (d.begin() + mid, d.end());

	deque_merge_sort(dLeft);
	deque_merge_sort(dRight);
	deque_merge(d, dLeft, dRight);
}

void PmergeMe::display_timer(struct timeval v1, struct timeval v2, struct timeval d1, struct timeval d2)
{
	double vector_t, deque_t;

	vector_t = (v2.tv_sec - v1.tv_sec) + (v2.tv_usec - v1.tv_usec) / 1000000.0;
	deque_t = (d2.tv_sec - d1.tv_sec) + (d2.tv_usec - d1.tv_usec) / 1000000.0;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << std::fixed << std::setprecision(6) << vector_t  << " s" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::vector: " << std::fixed << std::setprecision(6) << deque_t  << " s" << std::endl;
}

void PmergeMe::sort()
{
	try
	{
		std::vector<int> input = check_input();
		struct timeval v1, v2, d1, d2;
		output("Before:\t", input);

		gettimeofday(&v1, NULL);
		vector_init();
		vector_merge_sort(_vector);
		gettimeofday(&v2, NULL);

		gettimeofday(&d1, NULL);
		deque_init();
		deque_merge_sort(_deque);
		gettimeofday(&d2, NULL);

		output("After:\t", _vector);
		display_timer(v1, v2, d1, d2);
	}
	catch(const char * &e)
	{
		std::cerr << e << std::endl;
	}
}
