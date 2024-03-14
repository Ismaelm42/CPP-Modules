#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "AForm.hpp"
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		const std::string getName()const;
		int getGrade()const;
		void increment();
		void decrement();

		void signForm(AForm& rhs);
		void executeForm(const AForm& form);

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what()const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what()const throw();
		};
		class FormNotSigned: public std::exception
		{
			public:
				const char *what()const throw();
		};

		
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat& foo);

#endif
