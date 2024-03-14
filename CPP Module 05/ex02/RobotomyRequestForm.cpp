#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
:AForm(rhs.getName(),rhs.getSigningGrade(),rhs.getExecutionGrade())
{
	this->_target = rhs._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{	
	if (this->getSignature() == false)
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() > this->getExecutionGrade())
		throw Bureaucrat::GradeTooLowException();
	srand(time(NULL));
	int counter = 0;
	for (int i = 0; i < 30; i++)
	{
		if (i == 0)
		{
			sleep(1);
			std::cout << "D" << std::flush;
			sleep(1);
		}
		int random = rand() % 10;
		if (random <= 3)
		{
			sleep(random / 2);
			if (i >= 10)
			{
				std::cout << "." << std::flush;
				counter++;
				if (counter == 3)
					break;
			}
			else
				std::cout << "R" << std::flush;
		}
	}
	sleep(1);
	std::cout << std::endl;
	int random = rand() % 10;
	if (random >= 5)
		std::cout << this->_target << " has been rotomized" << std::endl;
	else
		std::cout << this->_target << " has not been rotomized" << std::endl;
}
