#include "Zombie.hpp"

Zombie *zombieHorde(int n, const std::string baseName)
{
    Zombie *horde = new Zombie[n];

    for (int i = 0; i < n; ++i)
        horde[i].setName(baseName + std::to_string(i));
    
    return horde;
}
