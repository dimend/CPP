#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name_(name), weapon_(NULL)
{

}

HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weapon_ = &newWeapon;
}

void HumanB::attack() const
{
    if (weapon_)
        std::cout << name_ << " attacks with their " << weapon_->getType() << "\n";
    else
        std::cout << name_ << " has no weapon to attack with!" << "\n";
}
