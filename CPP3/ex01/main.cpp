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
#include "ScavTrap.hpp"
#include <iostream>

void separator(const std::string& title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("CONSTRUCTION ORDER");
    {
        ScavTrap a("Guardian");
    } // destructor order visible here

    separator("SCAVTRAP STATS");
    ScavTrap b("Bob");

    // You should *not* print stats directly in real code,
    // but behavior will prove them.
    // Expected:
    // HP = 100, EP = 50, AD = 20

    separator("SCAVTRAP ATTACK (OVERRIDDEN)");
    b.attack("an intruder");   // must print ScavTrap-style message

    separator("INHERITED DAMAGE / REPAIR");
    b.takeDamage(30);          // HP -> 70
    b.beRepaired(10);          // HP -> 80, EP--

    separator("ENERGY DEPLETION");
    for (int i = 0; i < 51; i++)
        b.attack("air");       // last one should fail

    separator("GUARD GATE MODE");
    b.guardGate();             // must print gate keeper message

    separator("COPY CONSTRUCTOR");
    ScavTrap c(b);
    c.attack("copy target");
    c.guardGate();

    separator("COPY ASSIGNMENT");
    ScavTrap d("Temp");
    d = b;
    d.attack("assigned target");
    d.guardGate();

    separator("SELF ASSIGNMENT");
    d = d;
    d.attack("self");

    separator("END OF MAIN");
    return 0;
}
