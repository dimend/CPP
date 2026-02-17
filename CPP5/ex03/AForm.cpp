#include "AForm.hpp"
#include "Bureaucrat.hpp"

static void validateGrade(int grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    validateGrade(_gradeToSign);
    validateGrade(_gradeToExecute);
}

AForm::AForm(const AForm &other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
}
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;

    return *this;
}

AForm::~AForm()
{

}

const std::string& AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();

    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
    return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "AForm grade too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << AForm.getName()
       << ", AForm sign grade " << AForm.getGradeToSign()
       << ", execute grade " << AForm.getGradeToExecute()
       << ", signed: " << (AForm.getIsSigned() ? "yes" : "no");
    return os;
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!_isSigned)
        throw NotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();

    executeAction();
}

const char* AForm::NotSignedException::what() const noexcept
{
    return "AForm is not signed";
}
