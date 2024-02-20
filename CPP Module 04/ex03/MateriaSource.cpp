#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		this->_slots[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for(int i = 0; i < 4; i++)
			if (this->_slots[i])
				delete (_slots[i]);
		for(int i = 0; i < 4; i++)
			this->_slots[i] = other._slots[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
		if (this->_slots[i])
			delete _slots[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for(int i = 0; i < 4; i++)
		if (!this->_slots[i])
		{
			this->_slots[i] = m;
			return;
		}
	delete m;
	std::cout << "No slot left to learn new materia. Materia deleted." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
		if (this->_slots[i] && (this->_slots[i]->getType() == type))
			return this->_slots[i]->clone();
	std::cout << "Type not found." << std::endl;
	return 0;
}
