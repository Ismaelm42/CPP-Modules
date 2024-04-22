#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(std::string arg)
:_arg(arg)
{

}

RPN::RPN(const RPN& rhs)
{
	*this = rhs;
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		_arg = rhs._arg;
		_container = rhs._container;
	}
	return *this;
}

RPN::~RPN()
{

}

void RPN::get_result()
{
	for (int i = 0; _arg[i] != 0; i++)
	{
		if (_arg[i] == ' ')
			continue ;
		else if ((_arg[i] >= '0' && _arg[i] <= '9'))
		{
			if (_arg[i + 1] == ' ' || _arg[i + 1] == 0)
				_container.push(_arg[i] - '0');
			else
				throw ERROR;
		}
		else if (_arg[i] == '+' || _arg[i] == '-' || _arg[i] == '*' || _arg[i] == '/')
			operate_with_stack(_arg[i]);
		else
			throw ERROR;
	}
	if (_container.size() != 1)
		throw ERROR;
}

void RPN::operate_with_stack(char c)
{
	if (_container.empty() || _container.size() < 2)
		throw ERROR;
	
	int old_top = _container.top();
	_container.pop();
	if (c == '+')
		_container.top() = _container.top() + old_top;
	if (c == '-')
		_container.top() = _container.top() - old_top;
	if (c == '*')
		_container.top() = _container.top() * old_top;
	if (c == '/')
		_container.top() = _container.top() / old_top;
}

void RPN::print_result()
{
	try
	{
		get_result();
		std::cout << _container.top() << std::endl;
	}
	catch(const char* &e)
	{
		std::cerr << e << std::endl;
	}
}
