#include "Zombie.hpp"
#include <iostream>

void    randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
}