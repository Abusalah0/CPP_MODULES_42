/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:58:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/09 13:53:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap " << name << " copied." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage)
    : name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage)
{
    std::cout << "ClapTrap " << name << " created with custom attributes." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap " << name << " assigned." << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
   
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack! he has 0 points" << std::endl;
        return ;
    } 
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cant take damage because he has no point." << std::endl;
        return ;
    }
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Hit points left: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " cant repair because he has 0 point!" << std::endl;
        return ;
    }
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " points! Hit points: " << hitPoints << std::endl;
}
