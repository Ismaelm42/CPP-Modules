#include <iostream>

void	convert_to_uppercase(std::string& str)
{

	for (int n = 0; str[n] != 0; n++)
		str[n] = std::toupper(str[n]);
	std::cout << str;
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int n = 1; n < argc; n++)
		{
			std::string str = argv[n];
			convert_to_uppercase(str);
		}
	}
	std::cout << std::endl;
	return 0;
}
