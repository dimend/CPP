#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name_("Anonymous")
{
        std::cout << name_ << " got bit and is now a zombie!\n";
}

Zombie::Zombie(const std::string &name) : name_(name)
{
    std::cout << name_ << " got bit and is now a zombie!\n";
}

Zombie::~Zombie()
{
    std::cout << name_ << " got cured and is not a zombie anymore!\n";
}

void Zombie::announce() const
{
    std::cout << name_ <<": BraiiiiiiinnnzzzZ...\n";
}