#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#define ERROR "Error: Invalid RPN expression"

class RPN
{	
	private:
		RPN();
		std::string _arg;
		std::stack<int> _container;
	public:
		RPN(std::string arg);
		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);
		~RPN();

		void get_result();
		void operate_with_stack(char c);
		void print_result();

};

#endif
