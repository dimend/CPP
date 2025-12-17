/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:34:32 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:34:33 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

int main(int argc, char **argv)
{
    Zombie *horde = nullptr;

    if (argc < 2)
        return 1;

    try 
    {
        int n = std::stoi(argv[1]);

        if(n > 0)
        {
            horde = zombieHorde(n, "Zombie");

            for (int i = 0; i < n; ++i)
                horde[i].announce();
            
            delete[] horde;
        }
    } 
    catch (const std::exception& e)
    {
        std::cerr << "Invalid number / Alloc failed .\n";
        delete[] horde;
        return 1;
    }

    return 0;
}