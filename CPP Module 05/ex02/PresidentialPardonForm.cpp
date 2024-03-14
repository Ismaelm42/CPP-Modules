#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
:AForm(rhs.getName(),rhs.getSigningGrade(),rhs.getExecutionGrade())
{
	this->_target = rhs._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{	
	if (this->getSignature() == false)
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() > this->getExecutionGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
