#include <iostream> 

int	main()
{
	std::string stringSTR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringSTR;
	std::string &stringREF = stringSTR;

	std::cout << "Memory adress for STR is: " << &stringSTR << std::endl;
	std::cout << "Memory adress for PTR is: " << stringPTR << std::endl;
	std::cout << "Memory adress for REF is: " << &stringREF << std::endl;

	std::cout << "\nValue of STR is:\t\t" << stringSTR << std::endl;
	std::cout << "Value pointed by PTR is:\t" << *stringPTR << std::endl;
	std::cout << "Value pointed by REF is:\t" << stringREF << std::endl;

	return 0;
}
