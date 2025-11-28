#include <iostream>
#include <string>

class Harl
{
    public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		void debug();
		void info();
		void warning();
		void error();
		std::string levels[4];
		void (Harl::*functions[4])();
};