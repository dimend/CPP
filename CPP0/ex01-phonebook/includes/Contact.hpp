/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:25:18 by dimendon          #+#    #+#             */
/*   Updated: 2025/11/24 11:25:19 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    Contact();

    void setFirstName(const std::string &s);
    void setLastName(const std::string &s);
    void setNickname(const std::string &s);
    void setPhone(const std::string &s);
    void setSecret(const std::string &s);

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickname() const;
    const std::string &getPhone() const;
    const std::string &getSecret() const;

    bool isEmpty() const;

private:
    std::string firstName_;
    std::string lastName_;
    std::string nickname_;
    std::string phone_;
    std::string secret_;
};

#endif
