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


std::string BitcoinExchange::check_data(std::string& line, int *date, float& value)
{
	std::string err = "Bad input => ";
	int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (date[0] % 4 == 0 && (date[0] % 100 != 0 || date[0] % 400 == 0))
		days_per_month[1] = 29;

	for (int i = 0; line[i] != 0; i++)
		if ((line[i] < '0' || line[i] > '9') && (line[i] != '-' && line[i] != '.' && line[i] != '|' && line[i] != ' ' && line[i] != '\t'))
			return err + line;
	if (date[0] < 2009 || date[0] >= 10000 || (date[0] == 2009 && date[1] == 1 && date[2] == 1))
		return err + line;
	else if (line.find('-') == std::string::npos || line.find('|') == std::string::npos)
		return err + line;
	else if (line.find('-', line.find('-') + 1) == line.find('-') || line.find_last_of('|') != line.find('|'))
		return err + line;
	else if (line.find_last_of('.') != line.find('.'))
		return err + line;
	else if (date[0] < 0 || date[1] < 0 || date[1] > 12 || date[2] < 0 || date[2] > days_per_month[date[1] - 1])
		return err + line;
	else if (value < 0)
		return "Not a positive number";
	else if (line.find_last_of('-') != line.find('-', line.find('-') + 1))
		return err + line;
	else if (value > 1000)
		return "Too large number";
	return "";
}

void BitcoinExchange::get_data_line(std::string& line, std::map<std::string, std::string>& container, int& key)
{
	std::stringstream ss;
	std::string data[4] = {line.c_str(), line.c_str() + line.find('-') + 1, line.c_str() + line.find_last_of('-') + 1, line.c_str() + line.find('|') + 1};

	int date[3] = {std::atoi(data[0].c_str()), std::atoi(data[1].c_str()), std::atoi(data[2].c_str())};
	float value = std::atof(data[3].c_str());

	std::string check = check_data(line, date, value);
	if (check != "")
	{
		ss << "0000-00-00," << key;
		data[3] = check;
	}
	else
		ss << line.substr(0, 10) << "," << key;
 	container.insert(std::pair<std::string, std::string>(ss.str().c_str(), data[3]));
	key++;
}

void BitcoinExchange::read_data(std::map<std::string, std::string>& container, std::map<std::string, std::string>::iterator& it, std::string& last_line, std::string& line)
{
	std::stringstream ss;
	std::string date = line.substr(0, 10);


	if (date < it->first)
		return ;
	while (it != container.end() && date >= it->first)
	{
		if (it->first.substr(0, 10) == "0000-00-00")
		{
			it->second = "\033[0;31mError: " + it->second + "\033[0m";
			it++;
			return ;
		}
		ss << (std::atof(it->second.c_str()) * std::atof(last_line.substr(11, last_line.length()).c_str()));
		it->second = it->first.substr(0, 10) + " =>" + it->second + " = " + ss.str();
		ss.str("");
		it++;
	}
}

void BitcoinExchange::output_data(std::map<std::string, std::string>& container)
{
	std::map<std::string, std::string>::iterator it = container.begin();

	for (int i = 0; (size_t)i < container.size(); it++)
	{
		if (it == container.end())
			it = container.begin();
		if (std::atoi(it->first.substr(11, it->first.length()).c_str()) == i)
		{
			std::cout << it->second << std::endl;
			i++;
		}
	}
}

void BitcoinExchange::get_data()
{
	std::map<std::string, std::string> container;
	std::map<std::string, std::string>::iterator it;
	std::string last_line = "";
	std::string line;
	int key = 0;

	for (getline(_input, line); _input.eof() == false; getline(_input, line))
	{
		if (line != "date | value")
			get_data_line(line, container, key);
	}
	it = container.begin();
	for (getline(_data, line); _data.eof() == false; getline(_data, line))
	{
		if (line != "date,exchange_rate")
			read_data(container, it, last_line, line);
		if (it == container.end())
			break ;
		last_line = line;
	}
	while (it != container.end())
	{
		std::stringstream ss;
		ss << (std::atof(it->second.c_str()) * std::atof(last_line.substr(11, last_line.length()).c_str()));
		it->second = it->first.substr(0, 10) + " =>" + it->second + " = " + ss.str();
		it++;
	}
	output_data(container);
}
