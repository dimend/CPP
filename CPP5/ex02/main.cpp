#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void section(const std::string& title)
{
    std::cout << "\n===== " << title << " =====\n";
}

int main()
{
    // Seed RNG once for Robotomy
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    section("CREATE BUREAUCRATS");
    Bureaucrat low("Low", 150);
    Bureaucrat mid("Mid", 70);
    Bureaucrat high("High", 1);

    std::cout << low << std::endl;
    std::cout << mid << std::endl;
    std::cout << high << std::endl;

    section("CREATE FORMS");
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("bender");
    PresidentialPardonForm pardon("arthur");

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    section("EXECUTE WITHOUT SIGNING (should fail: not signed)");
    high.executeForm(shrub);
    high.executeForm(robo);
    high.executeForm(pardon);

    section("SIGNING TESTS");
    // Shrubbery needs sign 145
    low.signForm(shrub);    // should fail (150 > 145)
    mid.signForm(shrub);    // should succeed

    // Robotomy needs sign 72
    mid.signForm(robo);     // should succeed (70 <= 72)

    // Pardon needs sign 25
    mid.signForm(pardon);   // should fail (70 > 25)
    high.signForm(pardon);  // should succeed (1 <= 25)

    section("EXECUTION TESTS (grade too low vs success)");
    // Shrubbery exec 137
    low.executeForm(shrub);   // should fail (150 > 137)
    mid.executeForm(shrub);   // should succeed -> creates home_shrubbery

    // Robotomy exec 45
    mid.executeForm(robo);    // should fail (70 > 45)
    high.executeForm(robo);   // should succeed (random 50/50)

    // Pardon exec 5
    mid.executeForm(pardon);  // should fail (70 > 5)
    high.executeForm(pardon); // should succeed

    section("ROBOTOMY MULTI-RUN (see both success/failure)");
    for (int i = 0; i < 6; ++i)
        high.executeForm(robo);

    section("FINAL STATE PRINT");
    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    section("NOTE");
    std::cout << "Check your working directory for: home_shrubbery\n";
    std::cout << "(It should contain ASCII trees if Shrubbery execute succeeded.)\n";

    return 0;
}
