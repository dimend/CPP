#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "===== VALID FORM CREATION =====\n";
    try
    {
        Form tax("Tax Form", 50, 25);
        std::cout << tax << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== INVALID FORM CREATION =====\n";
    try
    {
        Form bad1("Bad High", 0, 25);
        std::cout << bad1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught (expected): " << e.what() << std::endl;
    }

    try
    {
        Form bad2("Bad Low", 50, 151);
        std::cout << bad2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught (expected): " << e.what() << std::endl;
    }

    std::cout << "\n===== SUCCESSFUL SIGNING =====\n";
    try
    {
        Bureaucrat boss("Boss", 40);
        Form permit("Work Permit", 50, 25);

        std::cout << boss << std::endl;
        std::cout << permit << std::endl;

        boss.signForm(permit);

        std::cout << "After signing:\n";
        std::cout << permit << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== FAILED SIGNING (GRADE TOO LOW) =====\n";
    try
    {
        Bureaucrat intern("Intern", 120);
        Form secret("Top Secret", 50, 10);

        std::cout << intern << std::endl;
        std::cout << secret << std::endl;

        intern.signForm(secret);

        std::cout << "After attempt:\n";
        std::cout << secret << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== SIGN TWICE TEST =====\n";
    try
    {
        Bureaucrat chief("Chief", 1);
        Form form("Double Sign", 10, 10);

        chief.signForm(form);
        chief.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n===== DONE =====\n";
    return 0;
}
