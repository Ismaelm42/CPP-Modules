#include "Data.hpp"

Data::Data()
:_id("default")
{

}

Data::Data(const std::string& str)
:_id(str)
{
	
}

Data::Data(const Data& rhs)
:_id(rhs._id)
{

}

Data& Data::operator=(const Data& rhs)
{
	if (this != &rhs)
		this->_id = rhs.get_id();
	return *this;
}

Data::~Data()
{

}

std::string Data::get_id() const
{
	return this->_id;
}
