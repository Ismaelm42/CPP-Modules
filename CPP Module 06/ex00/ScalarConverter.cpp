#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	(void)rhs;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert_char(std::string str)
{
	char c = str[0];
	if (c >= 32 && c <= 126)
		std::cout << "char:\t'" << c << "'" << std::endl;
	else
		std::cout << "char:\tnon displayable" << std::endl;
	int i = static_cast<int>(c);
	std::cout << "int:\t" << i << std::endl;
	float f = static_cast<float>(c);
	std::cout << "float:\t" << f << ".0f" << std::endl;
	double d = static_cast<double>(c);
	std::cout << "double:\t" << d << ".0" << std::endl;
}

void ScalarConverter::convert_int(std::string str)
{
	long i = strtol(str.c_str(), NULL, 10);
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << "Error: int out of range" << std::endl;
	else
	{
		i = static_cast<int>(i);
		char c = static_cast<char>(i);
		if (i < 0 || i > 127)
			std::cout << "char:\timpossible" << std::endl;
		else if (c >= 32 && c <= 126)
			std::cout << "char:\t" << "'" << c << "'" << std::endl;
		else
			std::cout << "char:\tnon displayable" << std::endl;
		std::cout << "int:\t" << i << std::endl;
		float f = static_cast<float>(i);
		std::cout << "float:\t" << f << ".0f" << std::endl;
		double d = static_cast<double>(i);
		std::cout << "double:\t" << d << ".0" << std::endl;
	}
}

void ScalarConverter::convert_float(std::string str)
{
	double f;
	if (str == "nanf")
		f = std::numeric_limits<float>::quiet_NaN();
	else if (str == "-inff")
		f = -std::numeric_limits<float>::infinity();
	else if (str == "+inff")
		f = std::numeric_limits<float>::infinity();
	else
	{	
		f = strtod(str.c_str(), NULL);
		if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
		{
			std::cout << "Error: float out of range" << std::endl;
			return ;
		}
	}
	f = static_cast<float>(f);
	char c = static_cast<int>(f);
	if (str == "nanf" || str == "-inff" || str == "+inff" || f < 0 || f > 127)
		std::cout << "char:\timpossible" << std::endl;
	else if (c >= 32 && c <= 126)
		std::cout << "char:\t" << "'" << c << "'"<< std::endl;
	else
		std::cout << "char:\tnon displayable" << std::endl;
	long i = static_cast<long>(f);
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << "int:\timpossible" << std::endl;
	else
		std::cout << "int:\t" << static_cast<int>(i) << std::endl;
	double d = static_cast<double>(f);
    std::ostringstream output;
    output << std::fixed << std::setprecision(6) << d;
    std::string float_str = output.str();
	if (float_str.find(".000000", 0) == std::string::npos)
	{
		std::cout << "float:\t" << f << "f" << std::endl;
		std::cout << "double:\t" << d << std::endl;
	}
	else
	{
		std::cout << "float:\t" << f << ".0f" << std::endl;
		std::cout << "double:\t" << d << ".0" << std::endl;
	}
}

void ScalarConverter::convert_double(std::string str)
{
	long double d;
	if (str == "nan")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (str == "-inf")
		d = -std::numeric_limits<double>::infinity();
	else if (str == "+inf")
		d = std::numeric_limits<double>::infinity();
	else
	{	
		d = strtold(str.c_str(), NULL);
		if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
		{
			std::cout << "Error: double out of range" << std::endl;
			return ;
		}
	}
	d = static_cast<double>(d);
	char c = static_cast<int>(d);
	if (str == "nan" || str == "-inf" || str == "+inf" || d < 0 || d > 127)
		std::cout << "char:\timpossible" << std::endl;
	else if (c >= 32 && c <= 126)
		std::cout << "char:\t" << "'" << c << "'"<< std::endl;
	else
		std::cout << "char:\tnon displayable" << std::endl;
	long i = static_cast<long>(d);
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
		std::cout << "int:\timpossible" << std::endl;
	else
		std::cout << "int:\t" << static_cast<int>(i) << std::endl;
	std::ostringstream output;
	output << std::fixed << std::setprecision(6) << d;
	std::string double_str = output.str();	
	if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
	{
		std::cout << "float:\timpossible" << std::endl;
		if (double_str.find(".000000", 0) == std::string::npos)
			std::cout << "double:\t" << d << std::endl;
		else
			std::cout << "double:\t" << d << ".0" << std::endl;
	}
	else if (double_str.find(".000000", 0) == std::string::npos)
	{
		std::cout << "float:\t" << d << "f" << std::endl;
		std::cout << "double:\t" << d << std::endl;
	}
	else
	{
		std::cout << "float:\t" << d << ".0f" << std::endl;
		std::cout << "double:\t" << d << ".0" << std::endl;
	}
}

std::string ScalarConverter::detect_type(char *arg)
{
	std::string	str;
	bool dot;

	str.assign(arg);
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return ("float");
	if (str == "-inf" || str == "+inf" || str == "nan")
		return ("double");
	if (str.length() == 1 && (*arg < '0' || *arg > '9'))
		return ("char");
	for (long unsigned i = 0; arg[i] != 0; i++)
	{
		if (i == 0 && (arg[i] == '+' || arg[i] == '-'))
			continue ;
		else if (i == (str.length() - 1) && arg[i] == 'f')
			return ("float");
		else if (arg[i] == '.' || arg[i] < '0' || arg[i] > '9')
		{
			if (arg[i] == '.' && dot == 0)
				dot = 1;
			else
			{
				std::cout << "invalid argument" << std::endl;
				return "";
			}
		}
	}
	if (dot == 1)
		return ("double");
	return ("int");
}

void ScalarConverter::convert(char *arg)
{
	std::string type = detect_type(arg);
	std::string str = arg;

	if (type == "char")
		convert_char(str);
	else if (type == "int")
		convert_int(str);
	else if (type == "float")
		convert_float(str);
	else if (type == "double")
		convert_double(str);
}
