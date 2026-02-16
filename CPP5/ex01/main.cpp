#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== BASIC CONSTRUCTION =====\n";
    try
    {
        Bureaucrat a("Alice", 2);
        Bureaucrat b("Bob", 149);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== INVALID CONSTRUCTION =====\n";
    try
    {
        Bureaucrat bad("Bad", 0);
        std::cout << bad << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught (expected): " << e.what() << std::endl;
    }

    std::cout << "\n===== INCREASE / DECREASE NORMAL =====\n";
    try
    {
        Bureaucrat c("Charlie", 75);
        std::cout << c << std::endl;
        c.increaseGrade();
        std::cout << c << std::endl;
        c.decreaseGrade();
        c.decreaseGrade();
        std::cout << c << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== INCREASE OUT OF RANGE =====\n";
    try
    {
        Bureaucrat top("Top", 1);
        std::cout << top << std::endl;
        top.increaseGrade();
        std::cout << top << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught (expected): " << e.what() << std::endl;
    }

    std::cout << "\n===== DECREASE OUT OF RANGE =====\n";
    try
    {
        Bureaucrat bottom("Bottom", 150);
        std::cout << bottom << std::endl;
        bottom.decreaseGrade();
        std::cout << bottom << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught (expected): " << e.what() << std::endl;
    }

    std::cout << "\n===== COPY & ASSIGNMENT =====\n";
    try
    {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned("Assigned", 100);

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;

        std::cout << "Assigning (assigned = original)\n";
        assigned = original;

        std::cout << "Original: " << original << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== DONE =====\n";
    return 0;
}
