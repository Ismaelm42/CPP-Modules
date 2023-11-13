#include "Contact.hpp"

void	Contact::add_contact()
{
	std::cout << "Enter first name: ";
	getline(std::cin, this->first_name);
	std::cout << "Enter last name: ";
	getline(std::cin, this->last_name);
	std::cout << "Enter nickname: ";
	getline(std::cin, this->nickname);
	std::cout << "Enter phone number: ";
	getline(std::cin, this->phone_number);
	std::cout << "Enter darkest secret: ";
	getline(std::cin, this->darkest_secret);
}
