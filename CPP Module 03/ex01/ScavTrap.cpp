#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
:ClapTrap()
{
	std::cout << "ScavTrap " << this->_name << " Default Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
:ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name << " Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& s_name)
:ClapTrap(s_name)
{
	std::cout << "ScavTrap " << this->_name << " Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " Default Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s_name)
{
	if (this != &s_name)
	{
		this->_name = s_name._name;
		this->_hit_points = s_name._hit_points;
		this->_energy_points = s_name._energy_points;
		this->_attack_damage = s_name._attack_damage;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks "
		<< target << ", causing " << _attack_damage << " of damage!" << std::endl;
	}
	else if (_hit_points == 0)
		std::cout << "ScavTrap " << _name << " is KO!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is exhausted! He can't do anything!" << std::endl;

}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
