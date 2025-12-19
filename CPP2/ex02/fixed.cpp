/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:47:12 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/19 16:19:23 by dimendon         ###   ########.fr       */
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

Fixed::Fixed(const int value)
{
	if (value > (INT_MAX >> _fractional_bits) || value < (INT_MIN >> _fractional_bits))
	{
		std::cerr << "Error: value is out of range" << std::endl;
		std::exit(1);
	}
	else
		_fixedpoint_value = value << _fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	if (value > INT_MAX / (1 << _fractional_bits) || value < INT_MIN / (1 << _fractional_bits))
	{
		std::cerr << "Error: value is out of range" << std::endl;
		std::exit(1);
	}
	else
		_fixedpoint_value = roundf(value * (1 << _fractional_bits));
}

float Fixed::toFloat()const
{
	return (float)_fixedpoint_value / (1 << _fractional_bits);
}

int Fixed::toInt()const
{
	return _fixedpoint_value >> _fractional_bits;
}

std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const
{
	return _fixedpoint_value > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
	return _fixedpoint_value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return _fixedpoint_value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return _fixedpoint_value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return _fixedpoint_value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return _fixedpoint_value != other.getRawBits();
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result;
	long long sum = static_cast<long long>(_fixedpoint_value) + static_cast<long long>(other.getRawBits());

	if ((sum > INT_MAX || sum < INT_MIN))
	{
		std::cerr << "Error: result is out of range" << std::endl;
		std::exit(1);
	}
	result.setRawBits(static_cast<int>(sum));
	return result;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;
	long long sub = static_cast<long long>(_fixedpoint_value) - static_cast<long long>(other.getRawBits());

	if ((sub > INT_MAX || sub < INT_MIN))
	{
		std::cerr << "Error: result is out of range" << std::endl;
		std::exit(1);
	}
	result.setRawBits(static_cast<int>(sub));
	return result;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result;
	long long multi = static_cast<long long>(_fixedpoint_value) * static_cast<long long>(other.getRawBits());		
	multi = multi >> _fractional_bits;
	
	if ((multi > INT_MAX || multi < INT_MIN))
	{
		std::cerr << "Error: result is out of range" << std::endl;
		std::exit(1);
	}
	result.setRawBits(static_cast<int>(multi));
	return result;
}

Fixed Fixed::operator/(const Fixed &other)
{
	if (other.getRawBits() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		std::exit(1);
	}
	Fixed result;
	long long div = (static_cast<long long>(_fixedpoint_value << _fractional_bits)) / static_cast<long long>(other.getRawBits());
	
	if ((div > INT_MAX || div < INT_MIN))
	{
		std::cerr << "Error: result is out of range" << std::endl;
		std::exit(1);
	}
	result.setRawBits(static_cast<int>(div));
	return result;
}

Fixed Fixed::operator++()
{
	if (_fixedpoint_value == INT_MAX)
	{
		std::cerr << "Error: value is out of range" << std::endl;
		std::exit(1);
	}
	++_fixedpoint_value;
	return *this;
}

Fixed Fixed::operator--()
{
	if (_fixedpoint_value == INT_MIN)
	{
		std::cerr << "Error: value is out of range" << std::endl;
		std::exit(1);
	}
	--_fixedpoint_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	if (_fixedpoint_value == INT_MAX)
	{
		std::cerr << "Error: value is out of range" << std::endl;
		std::exit(1);
	}
	Fixed result(*this);
	_fixedpoint_value++;
	return result;
}

Fixed Fixed::operator--(int)
{
	if (_fixedpoint_value == INT_MIN)
	{
		std::cerr << "Error: value is out of range" << std::endl;
		std::exit(1);
	}
	Fixed result(*this);
	_fixedpoint_value--;
	return result;
}
