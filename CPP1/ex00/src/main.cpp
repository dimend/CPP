#include "Zombie.hpp"

int main()
{
    //stack manual, delete end of execution
    Zombie z("Frank");
    z.announce();

    //stack announce and destroy immediately
    randomChump("Chump");

    //heap zombie
    Zombie* h = newZombie("Heap");
    h->announce();
    delete h;
}