#pragma once

#include <string>
#include <exception>
#include <ostream>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void increaseGrade();
    void decreaseGrade();

    void signForm(AForm &form);
    void executeForm(AForm const& form) const;

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const noexcept;
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const noexcept;
    };
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &obj);
