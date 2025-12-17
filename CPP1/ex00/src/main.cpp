/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:47:12 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 10:47:13 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *z = nullptr;

	try
	{
		z = newZombie("Alloced Zombie");
		z->announce();
		delete z;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Memory allocation failed\n";
		return (1);
	}
	randomChump("Stacked Zombie");
	return (0);
}