/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:25:35 by dimendon          #+#    #+#             */
/*   Updated: 2025/11/24 12:02:15 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentSize_(0), next_(0)
{

}

void PhoneBook::add(const Contact &c) 
{
    contacts_[next_] = c;

    next_++;
    if(next_ == 8)
        next_ = 0;

    if (currentSize_ < 8)
        currentSize_++;
}

int PhoneBook::size() const
{
    return currentSize_;
}

std::string PhoneBook::max10(const std::string &s)
{
    if (s.size() <= 10)
    {
        return std::string(10 - s.size(), ' ') + s;
    }
    else
    {
        return s.substr(0, 9) + ".";
    }
}

void PhoneBook::list() const
{
    std::cout << "---------------------------------------------\n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < currentSize_; ++i)
    {
        const Contact& c = contacts_[i];
        std::cout << "|" << max10(std::to_string(i))
                  << "|" << max10(c.getFirstName())
                  << "|" << max10(c.getLastName())
                  << "|" << max10(c.getNickname())
                  << "|\n";
    }
    std::cout << "---------------------------------------------\n";
}

bool PhoneBook::show(int index) const
{
    if (index < 0 || index >= currentSize_)
        return false;

    const Contact& c = contacts_[index];

    std::cout << "First Name : " << c.getFirstName() << "\n";
    std::cout << "Last Name  : " << c.getLastName()  << "\n";
    std::cout << "Nickname   : " << c.getNickname()  << "\n";
    std::cout << "Phone      : " << c.getPhone()     << "\n";
    std::cout << "Secret     : " << c.getSecret()    << "\n";
    return true;
}

