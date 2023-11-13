#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook(){this->index = 0; this->flag = false;}

PhoneBook::~PhoneBook(){}

static void	print_contacts(PhoneBook& Phonebook)
{
	int	index;

	std::cout << "|" << GREEN << std::setw(10) << "Index" << RESET;
	std::cout << "|" << GREEN << std::setw(10) << "First name" << RESET;
	std::cout << "|" << GREEN << std::setw(10) << "Last name" << RESET;
	std::cout << "|" << GREEN << std::setw(10) << "Nickname" << RESET;
	std::cout << "|";
	std::cout << std::endl;
	(Phonebook.flag == true) ? index = 8 : index = Phonebook.index;
	for(int i = 0; i < index ; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1);
		if (Phonebook.contacts[i].first_name.length() > 10)
			std::cout << "|" << Phonebook.contacts[i].first_name.substr(0, 9) << ".";
		else std::cout << "|" << std::setw(10) << Phonebook.contacts[i].first_name;
		if (Phonebook.contacts[i].last_name.length() > 10)
			std::cout << "|" << Phonebook.contacts[i].last_name.substr(0, 9) << ".";
		else std::cout << "|" << std::setw(10) << Phonebook.contacts[i].last_name;
		if (Phonebook.contacts[i].nickname.length() > 10)
			std::cout << "|" << Phonebook.contacts[i].nickname.substr(0, 9) << ".";
		else std::cout << "|" << std::setw(10) << Phonebook.contacts[i].nickname;
		std::cout << "|" << "\n";
	}
	std::cout << std::endl;
}

static void	print_contact_info(PhoneBook& Phonebook, int index)
{
	index--;
	std::cout << YELLOW << "First name: " << RESET << Phonebook.contacts[index].first_name << std::endl;
	std::cout << YELLOW << "Last name: " << RESET << Phonebook.contacts[index].last_name << std::endl;
	std::cout << YELLOW << "Nickname: " << RESET << Phonebook.contacts[index].nickname << std::endl;
	std::cout << YELLOW << "Phone number: " << RESET << Phonebook.contacts[index].phone_number << std::endl;
	std::cout << YELLOW << "Darkest secret: " << RESET << Phonebook.contacts[index].darkest_secret << std::endl;
}

void PhoneBook::add_contact()
{
	this->contacts[this->index].add_contact();
	(this->index == 7) ? this->index = 0, this->flag = true : this->index++; 
}

void PhoneBook::display_contacts()
{
	std::string input;
	int			index_typed;

	if (this->contacts[0].first_name.empty())
		std::cout << RED << "Your PhoneBook is empty, please, add a new contact\n" << RESET;
	else
	{
		print_contacts(*this);
		std::cout << YELLOW << "Enter an index to view additional information\n" << RESET;
		for (;;)
		{
			getline(std::cin, input);
			index_typed = std::atoi(input.c_str());
			if (index_typed < 1 || (index_typed > this->index && this->flag == false) || index_typed > 8)
				std::cout << RED << "Invalid index range, please, try again\n" << RESET;
			else
				break ;
		}
		print_contact_info(*this, index_typed);
	}
}
