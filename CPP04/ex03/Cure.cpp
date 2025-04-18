/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:41:13 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 15:56:02 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &other)
{
    // std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other)
    {
        // this->_type = other._type;
    }
    return (*this);
}

Cure::~Cure()
{
    // std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
