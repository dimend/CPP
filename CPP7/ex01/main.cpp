#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElem(const T &x)
{
    std::cout << x << " ";
}

void toUpper(std::string &s)
{
    for (size_t i = 0; i < s.size(); ++i)
        s[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
}

template <typename T>
void increment(T &x)
{
    x++;
}

int main()
{
    std::cout << "=== int array (non-const) ===\n";
    int a[] = {1, 2, 3, 4, 5};
    iter(a, 5, increment<int>);
    iter(a, 5, printElem<int>);
    std::cout << "\n\n";

    std::cout << "=== int array (const) ===\n";
    const int ca[] = {10, 20, 30};
    iter(ca, 3, printElem<int>);
    std::cout << "\n\n";

    std::cout << "=== string array (non-const) ===\n";
    std::string s[] = {"hello", "world", "cpp"};
    iter(s, 3, toUpper);
    iter(s, 3, printElem<std::string>);
    std::cout << "\n\n";

    std::cout << "=== double array (const) ===\n";
    const double d[] = {1.5, 2.5, 3.5};
    iter(d, 3, printElem<double>);
    std::cout << "\n";

    return 0;
}