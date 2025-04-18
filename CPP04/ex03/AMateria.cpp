/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:36:37 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 16:30:14 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default")
{
    // std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    // std::cout << "AMateria constructor called with type: " << type << std::endl;
}

AMateria::AMateria(AMateria const &other): _type(other._type)
{
    // std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
    // std::cout << "AMateria assignment operator called" << std::endl;
    (void) other;   
    return (*this);
}

AMateria::~AMateria()
{
    // std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    (void) target;
    // std::cout << "AMateria use called on " << target.getName() << std::endl;
}
