#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <array>
#include <string>

class PhoneBook
{
public:
    PhoneBook();

    void add(const Contact &c);
    void list() const;
    bool show(int index) const;
    int size() const;

private:
    static std::string fmt10(const std::string &s);
    std::array<Contact, 8> contacts_;
    int currentSize_;
    int next_;
};

#endif
