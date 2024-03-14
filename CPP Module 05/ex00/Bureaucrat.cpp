#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
:_name("default"), _grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
:_name(name), _grade(grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << grade << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
:_name(rhs._name), _grade(rhs._grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

const std::string Bureaucrat::getName()const
{
	return this->_name;
}
int Bureaucrat::getGrade()const
{
	return this->_grade;
}

void	Bureaucrat::increment()
{
	try
	{
		if (this->_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade--;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << this->getGrade() << std::endl;
	}
}

void	Bureaucrat::decrement()
{
	try
	{
		if (this->_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade++;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << this->getGrade() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what()const throw()
{
	return "Error: Grade too high: ";
}

const char *Bureaucrat::GradeTooLowException::what()const throw()
{
	return "Error: Grade too low: ";
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat& foo)
{
	stream << foo.getName() << ", bureaucrat grade " << foo.getGrade() << std::endl;
	return stream;
}
