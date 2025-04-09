/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:36:21 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/09 17:35:10 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// ostream overload

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}

// constructors and destructors

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

// setters and getters

int Fixed::getRawBits( void ) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

// casting functions

int Fixed::toInt( void ) const
{
    return _fixedPointValue >> _fractionalBits;
    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + other.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - other.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointValue * other.getRawBits()) >> _fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    if (other.getRawBits() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        result.setRawBits(0);
        return (result);
    }
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / other.getRawBits());
    return (result);
}

// logic operators

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_fixedPointValue > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_fixedPointValue < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_fixedPointValue >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_fixedPointValue <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_fixedPointValue == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_fixedPointValue != other.getRawBits());
}
// increment and decrement operators
Fixed &Fixed::operator++()
{
    ++_fixedPointValue;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++_fixedPointValue;
    return (temp);
}

Fixed &Fixed::operator--()
{
    --_fixedPointValue;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --_fixedPointValue;
    return (temp);
}

// min max functions

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
}
