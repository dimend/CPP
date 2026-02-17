#pragma once

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm
{
    protected:
        virtual void executeAction() const = 0;

    private:        
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        virtual ~AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

        void beSigned(const Bureaucrat &b);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void execute(Bureaucrat const& executor) const;

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
        class NotSignedException : public std::exception
        {
        public:
            const char* what() const noexcept;
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);