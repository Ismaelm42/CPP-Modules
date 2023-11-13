#include "Contact.hpp"

Contact::Contact(){};

Contact::~Contact(){};

static void	get_contact(std::string& string, std::string prompt)
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
	get_contact(this->first_name, "Enter first name: ");
	get_contact(this->last_name, "Enter last name: ");
	get_contact(this->nickname, "Enter nickname: ");
	get_contact(this->phone_number, "Enter phone number: ");
	get_contact(this->darkest_secret, "Enter darkest secret: ");
}
