#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <cstdio>

class PhoneBook
{
	public:
	static int index;
	Contact contacts[7];
	void display_contacts();
	std::ostream& operator<<(std::ostream& out);
};

void	print_contact_info(PhoneBook& phonebook, int index);

#endif
