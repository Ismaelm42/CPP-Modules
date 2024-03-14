#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signature;
		const int _signing_grade;
		const int _execution_grade;
	protected:
		std::string _target;
	public:
		AForm();
		AForm(std::string name, int signing_grade, int execution_grade);
		AForm(const AForm& rhs);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm();

		const std::string getName()const;
		bool getSignature()const;
		int getSigningGrade()const;
		int getExecutionGrade()const;

		bool beSigned(const Bureaucrat& foo);
		virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& outstream, const AForm& foo);

#endif
