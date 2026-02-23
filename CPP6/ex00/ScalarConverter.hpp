#pragma once

#include <string>

class ScalarConverter
{
    public:
        static void convert(const std::string &literal);

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter &operator=(const ScalarConverter &);
};
