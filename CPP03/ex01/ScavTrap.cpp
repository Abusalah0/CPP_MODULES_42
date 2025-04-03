/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:12:19 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/03 04:56:59 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap:: ScavTrap() : ClapTrap()
{
    this->guardMode = false;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20), guardMode(false)
{
    std::cout << "ScavTrap constructor called with name: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other), guardMode(other.guardMode)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->guardMode = other.guardMode;
    }
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " is out of energy or hit points!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        this->guardMode = !this->guardMode;
        if (this->guardMode)
            std::cout << "ScavTrap " << this->name << " is now in guard mode!" << std::endl;
        else
            std::cout << "ScavTrap " << this->name << " has exited guard mode!" << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << this->name << " is out of hit points or energy points" << std::endl;
    }
}
