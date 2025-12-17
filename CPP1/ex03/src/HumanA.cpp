/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:34:10 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:34:11 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name_, Weapon &weapon) : name_(name_), weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << name_ << " attacks with their " << weapon.getType() << "\n";
}