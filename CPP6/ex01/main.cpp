#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data d;
    d.n = 42;
    d.s = "hello";

    uintptr_t raw = Serializer::serialize(&d);
    Data *back = Serializer::deserialize(raw);

    std::cout << "original: " << &d << "\n";
    std::cout << "raw:      " << raw << "\n";
    std::cout << "back:     " << back << "\n";

    std::cout << "back->n = " << back->n << "\n";
    std::cout << "back->s = " << back->s << "\n";
}