#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, const std::string baseName)
{
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; ++i)
        horde[i] = Zombie(baseName + std::to_string(i));
    
    return horde;
}
