/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:34:02 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:34:03 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type_(type)
{

}

Weapon::~Weapon()
{

}

const std::string &Weapon::getType() const
{
    return type_;
}

void Weapon::setType(const std::string &type)
{
    type_ = type;
}
