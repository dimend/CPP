/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:47:12 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/19 14:34:36 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixedpoint_value(0)				                // 1. Default constructor
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)								// 2. Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)						// 3. Copy assignment operator
{
	std::cout << "Copy assignment operator called" << std::endl;
	_fixedpoint_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()      											// 4. Destructor
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
	return _fixedpoint_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedpoint_value = raw;
}