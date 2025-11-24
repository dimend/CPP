/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:25:30 by dimendon          #+#    #+#             */
/*   Updated: 2025/11/24 14:29:36 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>

static bool getline_safe(const std::string &prompt, std::string &out)
{
    std::cout << prompt;
    if (!std::getline(std::cin, out))
        return false;

    return true;
}

static std::string trim(const std::string& s)
{
    size_t a = s.find_first_not_of(" \t\r\n");
    size_t b = s.find_last_not_of (" \t\r\n");

    if (a == std::string::npos)
        return "";

    return s.substr(a, b - a + 1);
}

static Contact promptContact()
{
    Contact c;
    std::string s;

    while (true)
    {
        if (!getline_safe("First name: ", s))
            return Contact();

        s = trim(s);
        if (!s.empty()) 
        { 
            c.setFirstName(s); 
            break; 
        }
        std::cout << "Please enter a non-empty first name.\n";
    }

    while (true)
    {
        if (!getline_safe("Last name: ", s))
            return Contact();

        s = trim(s);
        if (!s.empty())
        { 
            c.setLastName(s);
            break;
        }
        std::cout << "Please enter a non-empty last name.\n";
    }

    while (true)
    {
        if (!getline_safe("Nickname : ", s))
            return Contact();;

        s = trim(s);
        if (!s.empty()) 
        {
            c.setNickname(s);
            break; 
        }
        std::cout << "Please enter a non-empty nickname.\n";
    }

    while (true)
    {
        if (!getline_safe("Phone    : ", s))
            return Contact();

        s = trim(s);
        if (!s.empty())
        {
            bool ok = true;
            for (size_t i = 0; i < s.size(); ++i)
            {
                if (!std::isdigit(s[i]))
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
            {
                std::cout << "Can only contain numbers.\n";
                continue;
            }
            c.setPhone(s);
            break;
        }
        std::cout << "Please enter a non-empty phone.\n";
    }

    while (true)
    {
        if (!getline_safe("Secret   : ", s))
            return Contact();;

        s = trim(s);
        if (!s.empty())
        {
            c.setSecret(s);
            break;
        }
        std::cout << "Please enter a non-empty secret.\n";
    }

    return c;
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc > 1)
    {
        std::cout << "Extra arguments detected.\n";
        return 0;
    }
    PhoneBook pb;
    std::string cmd;

    std::cout << " ---------------------------------------------\n";
    std::cout << "|                 PhoneBook                   |\n";
    std::cout << "|          ADD     SEARCH     EXIT            |\n";
    std::cout << " ---------------------------------------------\n";
    while (true)
    {
        std::cout << "-> ";
        if (!std::getline(std::cin, cmd))
        {
            std::cout << "\n";
            break;
        }

        if (cmd == "EXIT")
        {
            break;
        }
        else if (cmd == "ADD")
        {
            Contact c = promptContact();
            if (!c.isEmpty())
            {
                pb.add(c);
                std::cout << "Contact saved.\n";
            }
            else
            {
                std::cout << "Contact not saved (empty input).\n";
            }
        } 
        else if (cmd == "SEARCH")
        {
            if (pb.size() == 0)
            {
                std::cout << "PhoneBook is empty.\n";
                continue;
            }
            pb.list();
            
            while(true)
            {
                std::cout << "Enter index (0.." << pb.size() - 1 << "): ";
                std::string idxs;
                if (!std::getline(std::cin, idxs))
                {
                    std::cout << "\n";
                    break;
                }
                if (idxs.empty())
                {
                    std::cout << "Invalid index.\n";
                    continue;
                }
                size_t pos = 0;
                int idx;
                try
                {
                    idx = std::stoi(idxs, &pos);
                }
                catch (const std::exception &)
                {
                    std::cout << "Invalid index.\n";
                    continue;
                }
                if (pos != idxs.size())
                {
                    std::cout << "Invalid index.\n";
                    continue;
                }
                if (!pb.show(idx))
                {
                    std::cout << "Invalid index.\n";
                }
                break;
            }
        }
    }

    return 0;
}
