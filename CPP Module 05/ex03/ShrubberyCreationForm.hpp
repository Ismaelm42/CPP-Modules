#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& executor) const;

		class ErrorFile: public std::exception
		{
			public:
				const char *what()const throw();
		};
};

#endif
