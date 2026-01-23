#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main()
{
    std::cout << "\n========== BASIC POLYMORPHISM ==========\n";

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();

    std::cout << "\n========== BASE CLASS CALL ==========\n";

    const Animal* animal = new Animal();
    animal->makeSound();

    std::cout << "\n========== DESTRUCTION THROUGH BASE POINTER ==========\n";

    delete dog;
    delete cat;
    delete animal;

    std::cout << "\n========== WRONGANIMAL TEST ==========\n";

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

    wrongAnimal->makeSound();
    wrongCat->makeSound();

    delete wrongAnimal;
    delete wrongCat;

    std::cout << "\n========== STACK ALLOCATION TEST==========\n";

    {
        Dog d;
        Cat c;
        d.makeSound();
        c.makeSound();
    }

    return 0;
}
