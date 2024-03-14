#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
:AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
:AForm(rhs.getName(),rhs.getSigningGrade(),rhs.getExecutionGrade())
{
	this->_target = rhs._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignature() == false)
		throw Bureaucrat::FormNotSigned();
	if (executor.getGrade() > this->getExecutionGrade())
		throw Bureaucrat::GradeTooLowException();
	std::fstream file;
	std::string file_name = this->_target + "_shrubbery";
	try
	{
		file.open((this->_target + "_shrubbery").c_str(), std::fstream::out);
		if (file.fail() == true)
			throw ShrubberyCreationForm::ErrorFile();
	}
	catch(const std::exception& e)
	{
		throw ShrubberyCreationForm::ErrorFile();
	}
	file << this->_target << "/" << std::endl;
	file << "├─ node_modules/" << std::endl;
	file << "├─ public/" << std::endl;
	file << "│  ├─ favicon.ico" << std::endl;
	file << "│  ├─ index.html" << std::endl;
	file << "│  ├─ robots.txt" << std::endl;
	file << "├─ src/" << std::endl;
	file << "│  ├─ index.css" << std::endl;
	file << "│  ├─ index.js" << std::endl;
	file << "├─ .gitignore" << std::endl;
	file << "├─ package.json" << std::endl;
	file << "├─ README.md" << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::ErrorFile::what()const throw()
{
	return ("Error: Unable to open file");
}
