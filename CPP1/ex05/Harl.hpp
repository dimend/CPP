/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:33:27 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:33:28 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Harl
{
    public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		void debug();
		void info();
		void warning();
		void error();
		std::string levels[4];
		void (Harl::*functions[4])();
};