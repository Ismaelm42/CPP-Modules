#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <class T>
class Array
{	
	private:
		T *_array;
		unsigned int _length;

	public:
		Array()
		{
			this->_length = 100;
			this->_array = new T[this->_length];
		}

		Array(unsigned int length): _length(length)
		{
			this->_array = new T[this->_length];
		}

		Array(const Array& rhs)
		{
			*this = rhs;
		}

		Array& operator=(const Array& rhs)
		{
			if (this != &rhs)
			{
				this->_length = rhs._length;
				this->_array = new T[this->_length];
				for (unsigned int i = 0; i < this->_length; i++)
					this->_array[i] = rhs._array[i];
			}
			return *this;
		}

		T& operator[](const unsigned long nbr)
		{
			if (nbr > (this->_length - 1))
				throw Array<T>::OutOfBounds();
			return (this->_array[nbr]);
		}

		~Array()
		{
			if (this->_array)
				delete[] this->_array;
		}

		int size()
		{
			return this->_length;
		}

		class OutOfBounds: public std::exception
		{
			public:
				const char* what()const throw()
				{
					return ("Index out of bounds!");
				}
		};

};

#endif
