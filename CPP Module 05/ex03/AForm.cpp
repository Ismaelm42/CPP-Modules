#include "AForm.hpp"

AForm::AForm()
:_name("default"), _signature(false), _signing_grade(150), _execution_grade(150)
{

}

AForm::AForm(std::string name, int signing_grade, int execution_grade)
:_name(name), _signature(false), _signing_grade(signing_grade), _execution_grade(execution_grade)
{
	try
	{
		if (this->_signing_grade < 1 || this->_execution_grade < 1)
			throw AForm::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		if (this->_signing_grade < 1)
			std::cerr << e.what() << this->_signing_grade << std::endl;
		else
			std::cerr << e.what() << this->_execution_grade << std::endl;
	}
	try
	{
		if (this->_signing_grade > 150 || this->_execution_grade > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		if (this->_signing_grade > 150)
			std::cerr << e.what() << this->_signing_grade << std::endl;
		else
			std::cerr << e.what() << this->_execution_grade << std::endl;
	}
}

AForm::AForm(const AForm& rhs)
:_name(rhs._name), _signature(rhs._signature), _signing_grade(rhs._signing_grade), _execution_grade(rhs._execution_grade)
{

}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		this->_signature = rhs.getSignature();
	return *this;
}

AForm::~AForm()
{

}


const std::string AForm::getName()const
{
	return this->_name;
}

bool AForm::getSignature()const
{
	return this->_signature;
}

int AForm::getSigningGrade()const
{
	return this->_signing_grade;
}

int AForm::getExecutionGrade()const
{
	return this->_execution_grade;
}


bool AForm::beSigned(const Bureaucrat& foo)
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

const char *AForm::GradeTooHighException::what()const throw()
{
	return "Error: AForm grade too high: ";
}

const char *AForm::GradeTooLowException::what()const throw()
{
	return "Error: AForm grade too low: ";
}


std::ostream& operator<<(std::ostream& outstream, const AForm& foo)
{
	outstream << "\nAForm name:\t\t" << foo.getName() << std::endl
	<< "AForm signature:\t" << foo.getSignature() << std::endl
	<< "AForm signing grade:\t" << foo.getSigningGrade() << std::endl
	<< "AForm execution grade:\t" << foo.getExecutionGrade() << std::endl;
	return (outstream);
}
