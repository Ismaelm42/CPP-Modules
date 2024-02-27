#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signature;
		const int _signing_grade;
		const int _execution_grade;
	public:
		Form();
		Form(std::string name, int signing_grade, int execution_grade);
		Form(const Form& rhs);
		Form& operator=(const Form& rhs);
		~Form();

		const std::string getName()const;
		bool getSignature()const;
		int getSigningGrade()const;
		int getExecutionGrade()const;

		bool beSigned(const Bureaucrat& foo);

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what()const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what()const throw();
		};
};

std::ostream& operator<<(std::ostream& outstream, const Form& foo);

#endif
