#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : name_(name)
{
    std::cout << name_ << " got bit and is now a zombie!\n";
}

Zombie::~Zombie()
{
    std::cout << name_ << " got annihilated..\n";
}

void Zombie::announce() const
{
    std::cout << name_ <<": BraiiiiiiinnnzzzZ...\n";
}