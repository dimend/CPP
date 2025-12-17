/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:47:22 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 10:49:57 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
