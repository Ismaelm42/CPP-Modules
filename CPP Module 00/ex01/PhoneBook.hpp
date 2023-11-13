#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define GREEN "\x1B[38;2;17;245;120m"
# define YELLOW "\x1B[33m"
# define RED "\x1B[31m"
# define RESET "\x1b[0m"
# include "Contact.hpp"
# include <iostream>
# include <cstdlib>
# include <iomanip>

class PhoneBook
{
	public:
	PhoneBook();
	~PhoneBook();
	int		index;
	bool	flag;
	Contact	contacts[8];
	void	add_contact();
	void	display_contacts();
};

#endif

