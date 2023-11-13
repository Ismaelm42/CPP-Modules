#ifndef CONTACT_HPP
# define CONTACT_HPP
# define YELLOW "\x1B[33m"
# define RESET "\x1b[0m"
#include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		void add_contact();
};

#endif
