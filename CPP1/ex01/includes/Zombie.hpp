/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:34:36 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:34:37 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
public:
    Zombie();
    explicit Zombie(const std::string &name);                   //constructor
    ~Zombie();                                                  //destructor

    void announce() const;
    void setName(const std::string& name);

private:
    std::string name_;
};

Zombie *zombieHorde(int N, std::string name);

#endif