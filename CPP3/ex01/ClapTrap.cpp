/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:14:03 by dimendon          #+#    #+#             */
/*   Updated: 2026/01/16 16:41:18 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called for " << _name << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (!_energyPoints || !_hitPoints)
	{
        std::cout << "ClapTrap " << _name << " is either dead or has no energy." << std::endl;
        return;
    }
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
        return ;
    }

	if (amount >= static_cast<unsigned int>(_hitPoints))
		_hitPoints = 0;
	else
		_hitPoints -= amount;

	std::cout << "ClapTrap " << _name << " took " << amount << " damage. Now has " << _hitPoints << " hitpoints." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is either dead or has no energy." << std::endl;
        return;
    }

    _energyPoints--;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name << " repaired itself for " << amount << " and now has " << _hitPoints << " hitpoints." << std::endl;
}
