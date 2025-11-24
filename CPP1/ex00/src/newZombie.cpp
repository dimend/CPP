#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(const std::string name)
{
    return new Zombie(name);
}
