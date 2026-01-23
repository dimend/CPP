#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void separator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("ARRAY OF ANIMALS");

    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();

    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    separator("DESTRUCTION THROUGH BASE POINTER");

    for (int i = 0; i < size; i++)
        delete animals[i];

    separator("DEEP COPY TEST");

    Dog original;
    original.makeSound();

    original.getBrain()->ideas[0] = "I want a bone";

    Dog copy(original);

    copy.getBrain()->ideas[0] = "I want a steak";

    std::cout << "Original idea: "
              << original.getBrain()->ideas[0] << std::endl;
    std::cout << "Copy idea: "
              << copy.getBrain()->ideas[0] << std::endl;

    separator("END OF MAIN");
    return 0;
}
