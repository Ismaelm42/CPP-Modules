#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{
	Form paper("Paper", 34, 158);
	Bureaucrat Alfred("Alfred", 34);

	std::cout << paper << std::endl;
	Alfred.signForm(paper);
	std::cout << paper << std::endl;
	return 0;
}
