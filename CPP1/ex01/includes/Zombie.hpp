#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
    Zombie();
    explicit Zombie(const std::string &name);                   //constructor
    ~Zombie();                                                  //destructor

    void announce() const;

private:
    std::string name_;
};

Zombie* zombieHorde(int N, std::string name);

#endif