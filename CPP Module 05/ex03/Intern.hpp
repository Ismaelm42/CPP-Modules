#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		std::string _form_name;
		std::string _target;
	public:
		Intern();
		Intern(const std::string& form_name, const std::string& target);
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm* makeForm(const std::string& form_name, const std::string& target);
};

#endif
