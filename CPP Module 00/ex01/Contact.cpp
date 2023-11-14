#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

void	Contact::_get_contact(std::string& string, std::string prompt)
{
	string.clear();
	for (;string.empty();)
	{
		std::cout << YELLOW << prompt << RESET;
		getline(std::cin, string);
	}
}

void		Contact::add_contact()
{
	_get_contact(this->first_name, "Enter first name: ");
	_get_contact(this->last_name, "Enter last name: ");
	_get_contact(this->nickname, "Enter nickname: ");
	_get_contact(this->phone_number, "Enter phone number: ");
	_get_contact(this->darkest_secret, "Enter darkest secret: ");
}
