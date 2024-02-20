#include "Character.hpp"

Character::Character()
{
	for(int i = 0; i < 4; i++)
	{
		this->_slots[i] = 0;
		this->_inventory[i] = 0;
	}
}

Character::Character(std::string name)
:_name(name)
{
	for(int i = 0; i < 4; i++)
	{
		this->_slots[i] = 0;
		this->_inventory[i] = 0;
	}
}

Character::Character(const Character& other)
{
	*this = other;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for(int i = 0; i < 4; i++)
			if (this->_inventory[i])
				delete (_inventory[i]);
		for(int i = 0; i < 4; i++)
		{
			this->_inventory[i] = other._inventory[i]->clone();
			if (other._slots[i])
				this->_slots[i] = this->_inventory[i];
			else
				this->_slots[i] = 0;
		}
	}
	return *this;
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete _inventory[i];
}

std::string const& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int	i = 0;
	for(; i < 4; i++)
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			this->_slots[i] = this->_inventory[i];
			return;
		}
	if (i == 4)
		for (i = 0; i < 4; i++)
			if (!this->_slots[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = m;
				this->_slots[i] = this->_inventory[i];
				return;
			}
	delete m;
	std::cout << "No slot left to save a new materia. Materia deleted." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && (this->_slots[idx]))
	{
		this->_slots[idx] = 0;
		return;
	}
	std::cout << "No materia to unequip." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx < 4) && (this->_slots[idx]))
	{
		this->_slots[idx]->use(target);
		return;
	}
	std::cout << "No materia to use." << std::endl;
}
