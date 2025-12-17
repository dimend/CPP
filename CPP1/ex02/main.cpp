/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:34:17 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/05 11:34:18 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "brain value: " << brain << std::endl;
    std::cout << "brain memory address: " << &brain << std::endl;

    std::cout << std::endl;

    std::cout << "stringPTR value: " << *stringPTR << std::endl;
    std::cout << "stringPTR memory address: " << stringPTR << std::endl;

    std::cout << std::endl;

    std::cout << "stringREF value: " << stringREF << std::endl;
    std::cout << "stringREF memory address: " << &stringREF << std::endl;

    return 0;
}
