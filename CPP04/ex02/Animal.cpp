/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:15:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/14 17:00:51 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::setType(const std::string &t)
{
    this->type = t;
}
