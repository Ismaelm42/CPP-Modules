#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{
	// AForm *shrubb_form = new ShrubberyCreationForm("SHRUB");
	// AForm *robot_form = new RobotomyRequestForm("ROBOT");
	// AForm *pardon_form = new PresidentialPardonForm("PARDON");
	// Bureaucrat Alfred("Alfred", 5);

	// Alfred.signForm(*shrubb_form);
	// Alfred.executeForm(*shrubb_form);

	// Alfred.signForm(*robot_form);
	// Alfred.executeForm(*robot_form);

	// Alfred.signForm(*pardon_form);
	// Alfred.executeForm(*pardon_form);

	Intern someRandomIntern;
	AForm* form;

	form = someRandomIntern.makeForm("presidential pardon", "Bender");
	if (form != NULL)
		std::cout << *form << std::endl;
	delete form;
}
