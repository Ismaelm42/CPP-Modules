#include "iter.hpp"
#include <iostream>

int	main()
{
	std::string string_array[5] = {"str1", "str2", "str3", "str4", "str5"};
	int int_array[5] = {1, 2, 3, 4, 5};
	float float_array[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	char char_array[6] = "abcde";

	::iter <std::string> (string_array, sizeof(string_array) / sizeof(std::string), ::print);
	std::cout << std::endl;
	::iter <int> (int_array, sizeof(int_array) / sizeof(int), ::print);
	std::cout << std::endl;
	::iter <float> (float_array, sizeof(float_array) / sizeof(float), ::print);
	std::cout << std::endl;
	::iter <char> (char_array, sizeof(char_array) / sizeof(char), ::print);
}
