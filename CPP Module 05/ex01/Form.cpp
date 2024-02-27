#include "Form.hpp"

Form::Form()
:_name("default"), _signature(false), _signing_grade(150), _execution_grade(150)
{

}

Form::Form(std::string name, int signing_grade, int execution_grade)
:_name(name), _signature(false), _signing_grade(signing_grade), _execution_grade(execution_grade)
{
	try
	{
		if (this->_signing_grade < 1 || this->_execution_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (this->_signing_grade > 150 || this->_execution_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(std::exception& e)
	{
		if (this->_signing_grade < 1 || this->_signing_grade > 150)
			std::cerr << e.what() << this->_signing_grade << std::endl;
		else
			std::cerr << e.what() << this->_execution_grade << std::endl;
	}
}

Form::Form(const Form& rhs)
:_name(rhs._name), _signature(rhs._signature), _signing_grade(rhs._signing_grade), _execution_grade(rhs._execution_grade)
{

}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		this->_signature = rhs.getSignature();
	return *this;
}

Form::~Form()
{

}


const std::string Form::getName()const
{
	return this->_name;
}

bool Form::getSignature()const
{
	return this->_signature;
}

int Form::getSigningGrade()const
{
	return this->_signing_grade;
}

int Form::getExecutionGrade()const
{
	return this->_execution_grade;
}


bool Form::beSigned(const Bureaucrat& foo)
{
	try
	{
		if (foo.getGrade() > this->getSigningGrade())
			throw Bureaucrat::GradeTooLowException();
		this->_signature = true;
		return true;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << foo.getGrade() << std::endl;
		return false;
	}
}


const char *Form::GradeTooHighException::what()const throw()
{
	return "Error: Grade too high: ";
}

const char *Form::GradeTooLowException::what()const throw()
{
	return "Error: Grade too low: ";
}


std::ostream& operator<<(std::ostream& outstream, const Form& foo)
{
	outstream << "Form name:\t\t" << foo.getName() << std::endl
	<< "Form signature:\t\t" << foo.getSignature() << std::endl
	<< "Form signing grade:\t" << foo.getSigningGrade() << std::endl
	<< "Form execution grade:\t" << foo.getExecutionGrade() << std::endl;
	return (outstream);
}
