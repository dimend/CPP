#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
    const std::string _target;

protected:
    void executeAction() const;

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
};
