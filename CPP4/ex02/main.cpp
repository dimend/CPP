#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "\n========== ABSTRACT CLASS CHECK ==========\n";
    // Animal a; // ❌ should NOT compile (leave commented)

    std::cout << "\n========== POLYMORPHISM TEST ==========\n";

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();

    std::cout << "\n========== DESTRUCTION THROUGH BASE POINTER ==========\n";

    delete dog;
    delete cat;

    std::cout << "\n========== ARRAY OF ANIMALS ==========\n";

    const int size = 6;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();

    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n========== DELETE ARRAY ELEMENTS ==========\n";

    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n========== DEEP COPY TEST (DOG) ==========\n";

    Dog original;
    original.getBrain()->ideas[0] = "I want a bone";

    Dog copy(original);
    copy.getBrain()->ideas[0] = "I want a steak";

    std::cout << "Original idea: "
              << original.getBrain()->ideas[0] << std::endl;
    std::cout << "Copy idea: "
              << copy.getBrain()->ideas[0] << std::endl;

    std::cout << "\n========== DEEP COPY TEST (CAT) ==========\n";

    Cat cat1;
    cat1.getBrain()->ideas[0] = "I want to sleep";

    Cat cat2 = cat1;
    cat2.getBrain()->ideas[0] = "I want to eat";

    std::cout << "Cat1 idea: "
              << cat1.getBrain()->ideas[0] << std::endl;
    std::cout << "Cat2 idea: "
              << cat2.getBrain()->ideas[0] << std::endl;

    std::cout << "\n========== END OF MAIN ==========\n";
    return 0;
}
