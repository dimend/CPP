/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:25:27 by dimendon          #+#    #+#             */
/*   Updated: 2025/11/24 11:25:28 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    
}

void Contact::setFirstName(const std::string& s) 
{
    firstName_ = s;
}

void Contact::setLastName(const std::string& s)
{
    lastName_  = s;
}
void Contact::setNickname(const std::string& s)
{
    nickname_  = s;
}
void Contact::setPhone(const std::string& s)
{
    phone_     = s;
}
void Contact::setSecret(const std::string& s)
{
    secret_    = s;
}

const std::string& Contact::getFirstName() const
{
    return firstName_;
}
const std::string& Contact::getLastName()  const
{
    return lastName_;
}
const std::string& Contact::getNickname()  const
{
    return nickname_;
}
const std::string& Contact::getPhone()     const
{
    return phone_;
}
const std::string& Contact::getSecret()    const
{
    return secret_;
}

bool Contact::isEmpty() const
{
    return firstName_.empty() && lastName_.empty() && nickname_.empty()
           && phone_.empty() && secret_.empty();
}
