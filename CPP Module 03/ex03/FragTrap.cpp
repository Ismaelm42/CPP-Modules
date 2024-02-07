#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
:ClapTrap()
{
	std::cout << "FragTrap " << this->_name << " Default Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
:ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& f_name)
:ClapTrap(f_name)
{
	std::cout << "FragTrap " << this->_name << " Copy Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& f_name)
{
	if (this != &f_name)
	{
		this->_name = f_name._name;
		this->_hit_points = f_name._hit_points;
		this->_energy_points = f_name._energy_points;
		this->_attack_damage = f_name._attack_damage;
	}
	return *this;
}

void	FragTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "FragTrap " << _name << " attacks "
		<< target << ", causing " << _attack_damage << " of damage!" << std::endl;
	}
	else if (_hit_points == 0)
		std::cout << "FragTrap " << _name << " is KO!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " is exhausted! He can't do anything!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Hey, give me some high fives, guys!" << std::endl;
}
