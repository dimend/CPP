/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:25:21 by dimendon          #+#    #+#             */
/*   Updated: 2025/11/24 14:24:58 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    static std::string max10(const std::string &s);
    Contact contacts_[8];
    int currentSize_;
    int next_;
};

#endif
