/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:46:52 by dimendon          #+#    #+#             */
/*   Updated: 2025/12/19 15:04:49 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <climits>

class Fixed
{
    public:
        Fixed();                                // 1. Default constructor
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);              // 2. Copy constructor
        Fixed &operator=(const Fixed &other);   // 3. Copy assignment operator
        ~Fixed();                               // 4. Destructor
        int  getRawBits(void) const;
        void setRawBits(int const raw);
        float	toFloat(void) const;
		int		toInt(void) const;
    
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);
        static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

    private:
        int _fixedpoint_value;
        static const int    _fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &other);

#endif