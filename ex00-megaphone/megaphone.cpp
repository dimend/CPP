/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:22:36 by dimendon          #+#    #+#             */
/*   Updated: 2025/10/14 12:22:39 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;
    int size;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    while(i < argc)
    {
        std::string arg = argv[i];
        size = arg.size();

        j = 0;
        while(j < size)
        {
            if (arg[j] >= 'a' && arg[j] <= 'z')
                std::cout << static_cast<char>(arg[j] - 32);
            else
                std::cout << arg[j];

            j++;
        }

        if (i++ < argc - 1)
            std::cout << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
