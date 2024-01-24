#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
	<< "I really do!\n" << std::endl;
}
void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}
void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n"
	<< "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}
void	Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::_default(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	int i;

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(i = 0; i < 4; i++)
		if (level.compare(levels[i]) == 0)
			break;
	//Fallthrough error en Linux. Comprobar si en MacOS también da por la flag -Werror.
	//No olvidar de eliminar el break; si no da error en MacOS.
	switch (i)
	{
		case 0:
			this->_debug(); this->_info(); this->_warning(); this->_error();
			break;
		case 1:
			this->_info(); this->_warning(); this->_error();
			break;
		case 2:
			this->_warning(); this->_error();
			break;
		case 3:
			this->_error();
			break;
		default:
			this->_default();
	}
}
