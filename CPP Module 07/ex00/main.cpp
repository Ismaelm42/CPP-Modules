#include "T.hpp"
#include <iostream>

int	main()
{
	std::string str1 = "string1";
	std::string str2 = "string2";

	int a = 1;
	int b = 5;

	float c = 1.1f;
	float d = 5.5f;

	char e = 'e';
	char f = 'f';

	//swap
	::swap <std::string> (str1, str2);
	std::cout << "swap str1 = " << str1 << std::endl;
	std::cout << "swap str2 = " << str2 << std::endl;
	::swap <int> (a, b);
	std::cout << "swap int a = " << a << std::endl;
	std::cout << "swap int b = " << b << std::endl;
	::swap <float> (c, d);
	std::cout << "swap float c = " << c << std::endl;
	std::cout << "swap float d = " << d << std::endl;
	::swap <char> (e, f);
	std::cout << "swap char e = " << e << std::endl;
	std::cout << "swap char f = " << f << std::endl;

	std::cout << std::endl;

	//min
	std::cout << "min string = " << ::min <std::string> (str1, str2) << std::endl;
	std::cout << "min int = " << ::min <int> (a, b) << std::endl;
	std::cout << "min float = " << ::min <float> (c, d) << std::endl;
	std::cout << "min char = " << ::min <char> (e, f) << std::endl;
	
	std::cout << std::endl;

	//max
	std::cout << "max string = " << ::max <std::string> (str1, str2) << std::endl;
	std::cout << "max int = " << ::max <int> (a, b) << std::endl;
	std::cout << "max float = " << ::max <float> (c, d) << std::endl;
	std::cout << "max char = " << ::max <char> (e, f) << std::endl;
}
