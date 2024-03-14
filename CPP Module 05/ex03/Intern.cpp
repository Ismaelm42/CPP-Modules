#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const std::string& form_name, const std::string& target)
:_form_name(form_name), _target(target)
{

}

Intern& Intern::operator=(const Intern& rhs)
{
	if (this != &rhs)
	{
		this->_form_name = rhs._form_name;
		this->_target = rhs._target;
	}
	return *this;
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(const std::string& form_name, const std::string& target)
{
	AForm *ptr[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	for(; i < 3; i++)
	{
		if (form_name == forms[i])
			break;
	}
	for (int j = 0; j < 3; j++)
	{
		if (j != i)
		{
			std::cout << "j = " << j << std::endl;
			delete ptr[j];
		}
	}
	if (i != 3)
		return ((AForm *)ptr[i]);
	return (NULL);
}
