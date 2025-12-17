/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:33:48 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:33:49 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA
{
public:
	HumanA(const std::string &name_, Weapon &weapon);
	~HumanA();
	
	void attack();

private:
    std::string name_;
	Weapon &weapon;
};


#endif