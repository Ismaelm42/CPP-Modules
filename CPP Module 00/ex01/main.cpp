#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	for (;;)
	{
		std::cout << "Enter ADD, SEARCH or EXIT\n";
		getline(std::cin, input);
		if (input == "ADD")
		{
			phonebook.contacts[phonebook.index].add_contact();
			if (phonebook.index == 7) phonebook.index = 0;
		}
		else if (input == "SEARCH")
			phonebook.display_contacts();
		else if (input == "EXIT")
			break;
	}
	return 0;
}
