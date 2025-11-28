#include "Harl.hpp"

Harl :: Harl( void)
{
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
	this->functions[0] = &Harl::debug;
	this->functions[1] = &Harl::info;
	this->functions[2] = &Harl::warning;
	this->functions[3] = &Harl::error;
}

Harl :: ~Harl( void ) { }

void Harl :: debug( void )
{
	std::cout << "[Debug] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl :: info( void )
{
	std::cout << "[Info] I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl :: warning( void )
{
	std::cout << "[Warning] I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void Harl :: error( void )
{
	std::cout << "[Error] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl :: complain ( std::string level )
{
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {   
            (this->*functions[i])();
            return;
        }
    }
}
