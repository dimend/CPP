/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:46:52 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:37:30 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
public:
    explicit Zombie(const std::string &name);                   //constructor
    ~Zombie();                                                  //destructor

    void announce() const;

private:
    std::string name_;
};

Zombie  *newZombie(const std::string name);                     //heap, have to delete manually
void    randomChump(std::string name);

#endif