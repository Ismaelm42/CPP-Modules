#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
:ClapTrap("Def_clap_name"),ScavTrap(), FragTrap(), _name("Def")
{
	std::cout << "DiamondTrap " << this->_name << " Default Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap " << this->_name << " Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
    this->_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d_name)
:ClapTrap(d_name), ScavTrap(d_name), FragTrap(d_name)
{
	std::cout << "DiamondTrap " << this->_name << " Copy Constructor called" << std::endl;
	*this = d_name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d_name)
{
	if (this != &d_name)
	{
		this->_name = d_name._name;
		this->ClapTrap::_name = d_name.ClapTrap::_name;
		this->_hit_points = d_name._hit_points;
		this->_energy_points = d_name._energy_points;
    	this->_attack_damage = d_name._attack_damage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is: " << this->DiamondTrap::_name
	<< " / ClapTrap name is: " << this->ClapTrap::_name << std::endl;
}
