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

int main()
{
    std::cout << "\n========== CONSTRUCTORS ==========\n";
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    std::cout << "\n========== ATTACK ==========\n";
    a.attack("a tree");
    a.attack("a wall");

    std::cout << "\n========== TAKE DAMAGE ==========\n";
    a.takeDamage(3);
    a.takeDamage(10);
    a.takeDamage(1);

    std::cout << "\n========== ATTACK WHEN DEAD ==========\n";
    a.attack("nothing");

    std::cout << "\n========== REPAIR WHEN DEAD ==========\n";
    a.beRepaired(5);

    std::cout << "\n========== USE ENERGY ==========\n";
    ClapTrap c("Charlie");
    for (int i = 0; i < 11; i++)
        c.attack("air");

    std::cout << "\n========== REPAIR NO ENERGY ==========\n";
    c.beRepaired(5);

    std::cout << "\n========== REPAIR AFTER DAMAGE ==========\n";
    ClapTrap d("Delta");
    d.takeDamage(4);
    d.beRepaired(3);

    std::cout << "\n========== COPY CONSTRUCTOR ==========\n";
    ClapTrap e(d);
    e.attack("clone target");

    std::cout << "\n========== COPY ASSIGNMENT ==========\n";
    ClapTrap f("Foxtrot");
    f = d;
    f.attack("assigned target");

    std::cout << "\n========== SELF ASSIGNMENT ==========\n";
    f = f;
    f.attack("self");

    return 0;
}