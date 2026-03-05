#include "Identify.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base *generate(void)
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }

    int r = std::rand() % 3;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    return new C();
}

void identify(Base *p)
{
    if (!p)
    {
        std::cout << "Unknown\n";
        return;
    }

    if (dynamic_cast<A *>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown\n";
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A\n";
        return;
    }
    catch (const std::bad_cast &) {}

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B\n";
        return;
    }
    catch (const std::bad_cast &) {}

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C\n";
        return;
    }
    catch (const std::bad_cast &) {}

    std::cout << "Unknown\n";
}