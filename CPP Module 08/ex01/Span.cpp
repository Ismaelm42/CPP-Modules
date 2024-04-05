#include "Span.hpp"

Span::Span()
{
	array.reserve(100);
}

Span::Span(unsigned int N)
{
	array.reserve(N);
}

Span::Span(const Span& rhs)
{
	*this = rhs;
}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		array.reserve(rhs.array.capacity());
		array.assign(rhs.array.begin(), rhs.array.end());
	}
	return *this;
}

Span::Span(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	array.reserve(std::distance(end, begin));
	array.assign(begin, end);
}

Span::Span(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	array.reserve(std::distance(end, begin));
	array.assign(begin, end);
}

Span::Span(int *begin, int *end)
{
	array.reserve(end - begin);
	array.assign(begin, end);
}

Span::~Span()
{

}

void Span::addNumber(int nbr)
{
	if (array.size() >= array.capacity())
		throw Span::NoMoreElementsCanBeAdded();
	array.push_back(nbr);
}

int Span::shortestSpan()
{
	if (array.size() <= 1)
		throw Span::NotEnoughNumbersStored();
	Span t(*this);
	std::sort(t.array.begin(), t.array.end());
	int result = t.array[1] - t.array[0];
	for(unsigned int i = 2; i < t.array.size(); i++)
	{
		if (result == 0)
			return 0;
		if (result > (t.array[i] - t.array[i - 1]))
			result = t.array[i] - t.array[i - 1];
	}
	return result;
}

int Span::longestSpan()
{
	if (array.size() <= 1)
		throw Span::NotEnoughNumbersStored();
	Span t(*this);
	int min = t.array[0];
	int max = t.array[0];
	for(unsigned int i = 1; i < t.array.size(); i++)
	{
		if (min > std::min(t.array[i], t.array[i - 1]))
			min = std::min(t.array[i], t.array[i - 1]);
		if (max < std::max(t.array[i], t.array[i - 1]))
			max = std::max(t.array[i], t.array[i - 1]);
	}
	return max - min;
}

const char* Span::NotEnoughNumbersStored::what()const throw()
{
	return "Not enough numbers stored!";
}

const char* Span::NoMoreElementsCanBeAdded::what()const throw()
{
	return "No more elements can be added!";
}
