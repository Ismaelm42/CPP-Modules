#include "PhoneBook.hpp"

int PhoneBook::index = 0;

std::ostream& PhoneBook::operator<<(std::ostream& out)
{
	out << "|" << std::setw(10) << "INDEX";
	out << "|" << std::setw(10) << "FIRST NAME";
	out << "|" << std::setw(10) << "LAST NAME";
	out << "|" << std::setw(10) << "NICKNAME";
	out << "|";
	out << std::endl;
	out << "____________________________________________";
	out << std::endl;
	for(int i = 0; i < this->index; i++)
	{
		out << "|" << std::setw(10) << (i + 1);
		if (this->contacts[i].first_name.length() > 10)
			out << "|" << this->contacts[i].first_name.substr(0, 9) << ".";
		else out << "|" << std::setw(10) << this->contacts[i].first_name;
		if (this->contacts[i].last_name.length() > 10)
			out << "|" << this->contacts[i].last_name.substr(0, 9) << ".";
		else out << "|" << std::setw(10) << this->contacts[i].last_name;
		if (this->contacts[i].nickname.length() > 10)
			out << "|" << this->contacts[i].nickname.substr(0, 9) << ".";
		else out << "|" << std::setw(10) << this->contacts[i].nickname;
		out << "|" << "\n";
	}
	out << std::endl;
	return out;
}

void PhoneBook::display_contacts()
{
	std::string input;
	int			index_typed;

	if (this->index == 0)
	{
		std::cout << "Your PhoneBook is empty, please, add a new contact\n";
		return;
	}
	this->operator<<(std::cout);
	std::cout << "Type index to see more info\n";
	getline(std::cin, input);
	index_typed = std::atoi(input.c_str());
	if (index_typed < 1 || index_typed > (this->index + 1))
		std::cout << "Invalid index range\n";
	else
		print_contact_info(*this, (index - 1));
}

void	print_contact_info(PhoneBook& phonebook, int index)
{
	std::cout << phonebook.contacts[index].first_name << std::endl;
	std::cout << phonebook.contacts[index].last_name << std::endl;
	std::cout << phonebook.contacts[index].nickname << std::endl;
	std::cout << phonebook.contacts[index].phone_number << std::endl;
	std::cout << phonebook.contacts[index].darkest_secret << std::endl;
}
