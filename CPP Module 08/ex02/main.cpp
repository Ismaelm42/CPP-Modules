#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>

int main()
{
	std::cout << "Mutant Stack: " << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);


	std::cout << std::endl << std::endl;
	std::cout << "List: " << std::endl;
	std::list<int> mstack_list;
	mstack_list.push_back(5);
	mstack_list.push_back(17);
	std::cout << mstack_list.back() << std::endl;
	mstack_list.pop_back();
	std::cout << mstack_list.size() << std::endl;
	mstack_list.push_back(3);
	mstack_list.push_back(5);
	mstack_list.push_back(737);
	mstack_list.push_back(0);

	std::list<int>::iterator it_list = mstack_list.begin();
	std::list<int>::iterator ite_list = mstack_list.end();
	++it_list;
	--it_list;
	while (it_list != ite_list)
	{
		std::cout << *it_list << std::endl;
		++it_list;
	}
	std::stack<int, std::list<int> > s_list(mstack_list);
	return 0;


}

