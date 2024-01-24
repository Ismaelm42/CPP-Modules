#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
		void _default(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
