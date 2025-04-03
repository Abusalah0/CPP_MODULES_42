/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:52:16 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/03 19:33:39 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_Crap"), ScavTrap(), FragTrap(), name("Default")
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap constructor called with name: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    this->name = other.name;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
    }
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << " ClapTrap name:" << this->ClapTrap::name << std::endl;
}
