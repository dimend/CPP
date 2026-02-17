#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;

    AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
    AForm* f4 = someRandomIntern.makeForm("unknown form", "???");

    delete f1;
    delete f2;
    delete f3;
    delete f4;
}
