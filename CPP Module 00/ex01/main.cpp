#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main()
{
	PhoneBook	Phonebook;
	std::string	input;

	for (;;)
	{
		std::cout << GREEN << "Enter ADD, SEARCH or EXIT\n" << RESET;
		getline(std::cin, input);
		if (input == "ADD")
			Phonebook.add_contact();
		else if (input == "SEARCH")
			Phonebook.display_contacts();
		else if (input == "EXIT")
			break ;
	}
	return 0;
}
