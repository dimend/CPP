#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
private:
    const std::string _target;

protected:
    void executeAction() const;

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
};
