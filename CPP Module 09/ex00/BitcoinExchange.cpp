#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const std::string& filename)
:_data_name("data.csv"), _input_name(filename)
{
	_data.open(_data_name.c_str());
	_input.open(_input_name.c_str());
	if (_data.fail() || _input.fail())
		throw "Error: Could not open the file";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
{
	*this = rhs;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		_data_name = rhs._data_name;
		_input_name = rhs._input_name;
		_input.close();
		_data.close();
		_data.open(_data_name.c_str());
		_input.open(_input_name.c_str());
		if (_data.fail() || _input.fail())
			throw "Error: Could not open the file";
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	if (_data.is_open() == true)
		_data.close();
	if (_input.is_open() == true)
		_input.close();
}

bool BitcoinExchange::check_header(bool output, std::ifstream& file)
{
	std::string header;

	getline(file, header);
	if (!output && header != "date | value" && &file == &_input)
	{
		std::cerr << "Error: invalid header" << std::endl;
		return false;
	}
	else if (output)
		std::cout << header << std::endl;
	return true;
}

bool BitcoinExchange::check_format(std::string& line)
{
	if (line.length() < 14)
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			i++;
		if (line[i] < '0' || line[i] > '9')
			return false;
	}
	if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		return false;
	bool point;
	for (int i = 13; line[i] != 0; i++)
	{
		if (i == 13 && line[i] == '-')
			continue ;
		if ((line[i] < '0' || line[i] > '9') && line[i] != '.')
		{
			if (line[i] == '.' && point == false)
				point = true;
			else
				return false;
		}
	}
	return true;
}

std::string BitcoinExchange::check_date_and_value(std::string& line)
{
	int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int date[3];
	date[0] = std::atoi(line.substr(0, 4).c_str());
	date[1] = std::atoi(line.substr(5, 2).c_str());
	date[2] = std::atoi(line.substr(8, 2).c_str());

	if (date[0] % 4 == 0 && (date[0] % 100 != 0 || date[0] % 400 == 0))
		days_per_month[1] = 29;
	if (date[0] < 2009 || (date[0] == 2009 && date[1] == 1 && date[2] == 1))
		return "Error: wrong date";
	else if (date[0] < 0 || date[1] < 0 || date[1] > 12 || date[2] < 0 || date[2] > days_per_month[date[1] - 1])
		return "Error: wrong date";

	float value = std::atof(line.substr(13, line.length()).c_str());
	if (value > 1000)
		return "Error: too large number";
	if (value < 0)
		return "Error: not a positive number";
	return line.substr(13, line.length());
}


void BitcoinExchange::get_data_line(std::string& line, std::map<std::string, std::string>& container)
{
	if (line.empty())
		container.insert(std::pair<std::string, std::string>("", ""));
	else if (check_format(line) == false)
		container.insert(std::pair<std::string, std::string>(line, "Error: bad input"));
	else
		container.insert(std::pair<std::string, std::string>(line, check_date_and_value(line)));
}

void BitcoinExchange::read_data(std::map<std::string, std::string>& container)
{
	std::stringstream ss;
	std::string last_line;
	std::string line;
	bool eof = false;

	check_header(false, _data);
	getline(_data, line);
	for (std::map<std::string, std::string>::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first == "" || it->second.find("Error") != std::string::npos)
			continue ;
		while (line.substr(0, 10) <= it->first.substr(0, 10) && !eof)
		{
			if (line != "")
				last_line = line;
			if (!getline(_data, line))
				eof = true;
		}
		ss << std::atof(it->second.c_str()) * std::atof(last_line.substr(11, last_line.length()).c_str());
		it->second = ss.str();
		ss.str("");
	}
}

void BitcoinExchange::output_data(std::map<std::string, std::string>& container)
{
	std::map<std::string, std::string>::iterator it;
	std::string line;

	_input.clear();
	_input.seekg(0, std::ios::beg);
	check_header(true, _input);
	while (getline(_input, line))
	{
		for (it = container.begin(); line != it->first; it++)
			if (it == container.end())
				it = container.begin();
		if (it->first == "")
			std::cout << std::endl;
		else if (it->second.find("Error: bad input") != std::string::npos)
			std::cout << "\033[0;31m" << it->second << " => " << it->first << "\033[0m" << std::endl;
		else if (it->second.find("Error") != std::string::npos)
			std::cout << "\033[0;31m" << it->second << "\033[0m" << std::endl;
		else
			std::cout << it->first.substr(0, 10) << " => " << it->first.substr(13, it->first.length()) << " = " << it->second << std::endl;
	}
}

void BitcoinExchange::get_data()
{
	std::map<std::string, std::string> container;
	std::map<std::string, std::string>::iterator it;
	std::string line;

	if (check_header(false, _input) == false)
		return ;
	while (getline(_input, line))
			get_data_line(line, container);	
	read_data(container);
	output_data(container);
}
