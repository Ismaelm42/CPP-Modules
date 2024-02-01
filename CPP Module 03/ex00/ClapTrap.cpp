#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
:_name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
:_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c_name)
:_name(c_name._name), _hit_points(c_name._hit_points), _energy_points(c_name._energy_points), _attack_damage(c_name._attack_damage)
{
	std::cout << "Copy Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c_name)
{
	if (this != &c_name)
	{
		this->_name = c_name._name;
		this->_hit_points = c_name._hit_points;
		this->_energy_points = c_name._energy_points;
		this->_attack_damage = c_name._attack_damage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks "
		<< target << ", causing " << _attack_damage << " of damage!" << std::endl;
	}
	else if (_hit_points == 0)
		std::cout << "ClapTrap " << _name << " is KO!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is exhausted! He can't do anything!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > 0)
	{
		if (amount >= _hit_points)
			_hit_points = 0;
		else
			_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " has taken " << amount << " damage!"
		<< " ClapTrap " << _name << "'s hit points are now " << _hit_points << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already KO!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		_hit_points += amount;
		std::cout << "ClapTrap " << _name << " has repaired himself!"
		<< " ClapTrap " << _name << "'s hit points are now " << _hit_points << std::endl;
	}
	else if (_hit_points == 0)
		std::cout << "ClapTrap " << _name << " is KO!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is exhausted! He can't do anything!" << std::endl;
}
