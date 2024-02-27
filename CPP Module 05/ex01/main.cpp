#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{
	Form paper("Paper", 35, 0);
	Bureaucrat Alfred("Alfred", 47);

	Alfred.signForm(paper);
	return 0;
}
