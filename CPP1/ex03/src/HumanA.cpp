#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name_, Weapon &weapon) : name_(name_), weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon.getType() << "\n";
}