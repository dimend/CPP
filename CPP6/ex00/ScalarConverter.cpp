#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
     (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

enum LiteralType
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_PSEUDO,
    TYPE_INVALID
};

static bool isPseudo(const std::string &s)
{
    return (s == "nan" || s == "+inf" || s == "-inf" ||
            s == "nanf" || s == "+inff" || s == "-inff");
}

static bool isCharLiteral(const std::string &s)
{
    return (s.length() == 1 &&
            std::isprint(static_cast<unsigned char>(s[0])) &&
            !std::isdigit(static_cast<unsigned char>(s[0])) &&
            std::isalpha(static_cast<unsigned char>(s[0])));
}

static bool isIntLiteral(const std::string &s)
{
    if (s.empty())
        return false;

    size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;

    if (i == s.length())
        return false;

    for (; i < s.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }
    return true;
}

static bool isFloatLiteral(const std::string &s)
{
    if (s.length() < 2)
        return false;

    if (s[s.length() - 1] != 'f')
        return false;

    std::string core = s.substr(0, s.length() - 1);

    char* end;
    errno = 0;
    std::strtod(core.c_str(), &end);

    return (end != core.c_str() && *end == '\0');
}

static bool isDoubleLiteral(const std::string &s)
{
    if (s.empty())
        return false;

    char* end;
    errno = 0;
    std::strtod(s.c_str(), &end);

    return (end != s.c_str() && *end == '\0');
}

static LiteralType detectType(const std::string &literal)
{
    if (isPseudo(literal))
        return TYPE_PSEUDO;

    if (isCharLiteral(literal))
        return TYPE_CHAR;

    if (isIntLiteral(literal))
        return TYPE_INT;

    if (isFloatLiteral(literal))
        return TYPE_FLOAT;

    if (isDoubleLiteral(literal))
        return TYPE_DOUBLE;

    return TYPE_INVALID;
}

void ScalarConverter::convert(const std::string &literal)
{
    LiteralType type = detectType(literal);

    double value = 0.0;
    bool ok = true;

    // --- PARSE TO MASTER DOUBLE ---
    switch (type)
    {
        case TYPE_CHAR:
            value = static_cast<double>(literal[0]);
            break;

        case TYPE_INT:
            value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
            break;

        case TYPE_FLOAT:
            value = std::strtod(literal.substr(0, literal.size() - 1).c_str(), NULL);
            break;

        case TYPE_DOUBLE:
            value = std::strtod(literal.c_str(), NULL);
            break;

        case TYPE_PSEUDO:
            if (literal == "nan" || literal == "nanf")
                value = std::numeric_limits<double>::quiet_NaN();
            else if (literal == "+inf" || literal == "+inff")
                value = std::numeric_limits<double>::infinity();
            else
                value = -std::numeric_limits<double>::infinity();
            break;

        default:
            ok = false;
    }

    // ================= CHAR =================
    std::cout << "char: ";
    if (!ok || std::isnan(value) || std::isinf(value) ||
        value < 0 || value > 127)
    {
        std::cout << "impossible\n";
    }
    else
    {
        char c = static_cast<char>(value);
        if (std::isprint(static_cast<unsigned char>(c)))
            std::cout << "'" << c << "'\n";
        else
            std::cout << "Non displayable\n";
    }

    // ================= INT =================
    std::cout << "int: ";
    if (!ok || std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
    {
        std::cout << "impossible\n";
    }
    else
    {
        std::cout << static_cast<int>(value) << "\n";
    }

    // ================= FLOAT =================
    std::cout << "float: ";
    if (!ok)
    {
        std::cout << "impossible\n";
    }
    else if (std::isnan(value))
    {
        std::cout << "nanf\n";
    }
    else if (std::isinf(value))
    {
        std::cout << (value < 0 ? "-inff\n" : "+inff\n");
    }
    else
    {
        float f = static_cast<float>(value);
        std::cout << std::fixed << std::setprecision(1) << f << "f\n";
    }

    // ================= DOUBLE =================
    std::cout << "double: ";
    if (!ok)
    {
        std::cout << "impossible\n";
    }
    else if (std::isnan(value))
    {
        std::cout << "nan\n";
    }
    else if (std::isinf(value))
    {
        std::cout << (value < 0 ? "-inf\n" : "+inf\n");
    }
    else
    {
        std::cout << std::fixed << std::setprecision(1)
                  << static_cast<double>(value) << "\n";
    }
}
