#pragma once

#include <string>
#include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    std::string ideas[100];
};
