/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:04:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/30 17:04:59 by abdsalah         ###   ########.fr       */
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

private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP