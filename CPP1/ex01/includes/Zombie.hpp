#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
public:
    Zombie();
    explicit Zombie(const std::string &name);                   //constructor
    ~Zombie();                                                  //destructor

    void announce() const;
    void setName(const std::string& name);

private:
    std::string name_;
};

Zombie *zombieHorde(int N, std::string name);

#endif