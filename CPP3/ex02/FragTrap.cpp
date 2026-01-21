#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("FragTrap")
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name):ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap " << _name << " destructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);

    std::cout << "FragTrap copy assignment operator called for " << _name << std::endl;
    return *this;
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap "<< _name << " requests a positive high five!" << std::endl;
}