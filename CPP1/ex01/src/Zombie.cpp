/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:34:29 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:34:30 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name_("Anonymous")
{
    std::cout << name_ << " got bit and is now a zombie!\n";
}

Zombie::Zombie(const std::string &name) : name_(name)
{
    std::cout << name_ << " got bit and is now a zombie!\n";
}

Zombie::~Zombie()
{
    std::cout << name_ << " got annihilated..\n";
}

void Zombie::announce() const
{
    std::cout << name_ <<": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(const std::string &name)
{
    this->name_ = name;
}