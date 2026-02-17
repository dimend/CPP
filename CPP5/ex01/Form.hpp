#pragma once

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
    private:        
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        ~Form();
        Form(const std::string &name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);

        void beSigned(const Bureaucrat &b);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

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

std::ostream& operator<<(std::ostream& os, const Form& form);