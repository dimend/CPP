/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:13:48 by dimendon          #+#    #+#             */
/*   Updated: 2026/01/16 16:43:12 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

void separator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("CONSTRUCTION ORDER");
    {
        FragTrap a("Guardian");
    } // destructor order should be visible here

    separator("FRAGTRAP STATS");
    FragTrap b("Bob");
    // Expected stats:
    // HP = 100
    // Energy = 100
    // Attack damage = 30

    separator("FRAGTRAP ATTACK");
    b.attack("an enemy");   // must print FragTrap message, damage = 30

    separator("INHERITED DAMAGE / REPAIR");
    b.takeDamage(40);       // HP -> 60
    b.beRepaired(20);       // HP -> 80, energy--

    separator("ENERGY DEPLETION");
    for (int i = 0; i < 101; i++)
        b.attack("air");    // last one should fail (energy = 100)

    separator("SPECIAL ABILITY");
    b.highFivesGuys();      // must print positive high-fives message

    separator("COPY CONSTRUCTOR");
    FragTrap c(b);
    c.attack("copy target");
    c.highFivesGuys();

    separator("COPY ASSIGNMENT");
    FragTrap d("Temp");
    d = b;
    d.attack("assigned target");
    d.highFivesGuys();

    separator("SELF ASSIGNMENT");
    d = d;
    d.attack("self");

    separator("END OF MAIN");
    return 0;
}

