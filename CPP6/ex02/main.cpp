#include "Identify.hpp"
#include <iostream>

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        Base *p = generate();

        std::cout << "identify(ptr): ";
        identify(p);

        std::cout << "identify(ref): ";
        identify(*p);

        delete p;
        std::cout << "----\n";
    }
    return 0;
}