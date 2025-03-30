/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:04:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/30 18:52:29 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const Fixed &copy);
    ~Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed &operator=(const Fixed &copy);

    float toFloat(void) const;
    int toInt(void) const;
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    Fixed &operator++(); // Pre-increment
    Fixed operator++(int); // Post-increment
    Fixed &operator--(); // Pre-decrement
    Fixed operator--(int); // Post-decrement
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP