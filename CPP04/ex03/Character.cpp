/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:39:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/17 16:53:23 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < MAX_INV_SIZE; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
    std::cout << "Character constructor called with name: " << name << std::endl;
    for (int i = 0; i < MAX_INV_SIZE; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &other)
{
    std::cout << "Character copy constructor called" << std::endl;
    this->_name = other._name;
    this->copyInventory(other);
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->clearInventory();
        this->copyInventory(other);
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    this->clearInventory();
}

void Character::clearInventory()
{
    for (int i = 0; i < MAX_INV_SIZE; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::setName(std::string name)
{
    this->_name = name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < MAX_INV_SIZE; ++i)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << "Equipped " << m->getType() << " to " << _name << std::endl;
            return;
        }
    }
    std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < MAX_INV_SIZE && _inventory[idx])
    {
        std::cout << "Unequipped " << _inventory[idx]->getType() << " from " << this->_name << std::endl;
    }
    else
        std::cout << "Invalid index or no materia to unequip" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < MAX_INV_SIZE && _inventory[idx])
    {
        std::cout << this->_name << " uses " << _inventory[idx]->getType() << " on " << target.getName() << std::endl;
        _inventory[idx]->use(target);
    }
    else
        std::cout << "Invalid index or no materia to use" << std::endl;
}
AMateria* Character::getMateria(int idx) const
{
    if (idx >= 0 && idx < MAX_INV_SIZE)
        return _inventory[idx];
    return NULL;
}

void Character::copyInventory(const Character &other)
{
    for (int i = 0; i < MAX_INV_SIZE; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}
