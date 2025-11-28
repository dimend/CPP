#include "Zombie.hpp"

int main()
{
    Zombie *z = nullptr;

	try
	{
		z = newZombie("Alloced Zombie");
		z->announce();
		delete z;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Memory allocation failed\n";
		return (1);
	}
	randomChump("Stacked Zombie");
	return (0);
}