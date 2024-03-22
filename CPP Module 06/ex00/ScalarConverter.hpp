#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();
	public:

		static void convert_char(std::string str);
 		static void convert_int(std::string str);
		static void convert_float(std::string str);
		static void convert_double(std::string str);
		static std::string detect_type(char *arg);
		static void	convert(char *arg);
};

#endif
