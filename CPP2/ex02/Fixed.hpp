/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:46:52 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/17 14:44:22 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    public:
        Fixed();                                // 1. Default constructor
        Fixed(const Fixed& other);              // 2. Copy constructor
        Fixed& operator=(const Fixed& other);   // 3. Copy assignment operator
        ~Fixed();                               // 4. Destructor

    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif