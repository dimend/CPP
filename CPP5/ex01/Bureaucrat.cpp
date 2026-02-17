#include "Bureaucrat.hpp"
#include "Form.hpp"

static void validateGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << "Default Bureaucrat constructor called\n";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    validateGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        this->_grade = other._grade;

    return *this;
}

const std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increaseGrade()
{
    std::cout << "Trying to increase grade...\n";
    validateGrade(this->_grade - 1);
    --this->_grade;
}

void Bureaucrat::decreaseGrade()
{
    std::cout << "Trying to decrease grade...\n";
    validateGrade(this->_grade + 1);
    ++this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Bureaucrat grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Bureaucrat grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName()
                  << " signed "
                  << form.getName()
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << this->getName()
                  << " couldn’t sign "
                  << form.getName()
                  << " because "
                  << e.what()
                  << std::endl;
    }
}