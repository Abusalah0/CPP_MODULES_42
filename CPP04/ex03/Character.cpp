/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:39:23 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 18:31:39 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
    // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < MAX_INV_SIZE; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; i ++)
        _dropped_items[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
    // std::cout << "Character constructor called with name: " << name << std::endl;
    for (int i = 0; i < MAX_INV_SIZE; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 100; i ++)
        _dropped_items[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < MAX_INV_SIZE; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone(); // deep copy
        else
            _inventory[i] = NULL;
    }

    for (int i = 0; i < 100; i++)
    {
        if (other._dropped_items[i])
            _dropped_items[i] = other._dropped_items[i]->clone(); // deep copy
        else
            _dropped_items[i] = NULL;
    }
}

Character& Character::operator=(const Character& other)
{
    if (this == &other)
        return *this;

    _name = other._name;

    for (int i = 0; i < MAX_INV_SIZE; i++)
    {
        delete _inventory[i];
        _inventory[i] = NULL;
    }

    for (int i = 0; i < MAX_INV_SIZE; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone(); // deep copy
        else
            _inventory[i] = NULL;
    }

    for (int i = 0; i < 100; i++)
    {
        delete _dropped_items[i];
        _dropped_items[i] = NULL;
    }

    for (int i = 0; i < 100; i++)
    {
        if (other._dropped_items[i])
            _dropped_items[i] = other._dropped_items[i]->clone(); // deep copy
        else
            _dropped_items[i] = NULL;
    }

    return *this;
}

Character::~Character()
{
    // std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 100; i ++)
        delete _dropped_items[i];
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
            // std::cout << "Equipped " << m->getType() << " to " << _name << std::endl;
            return ;
        }
    }
    // std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int i)
{
    if (i >= 0 && i < MAX_INV_SIZE && _inventory[i])
    {
        for (int j = 0; j < 100; j++)
        {
            if (_dropped_items[j] == NULL)
            {
                _dropped_items[j] = _inventory[i];
                _inventory[i] = NULL;
                // std::cout << "Unequipped and stored dropped item at index " << j << std::endl;
                return;
            }
        }
        // std::cout << "Dropped items storage is full" << std::endl;
    }
    // else
    // {
        // std::cout << "Invalid index or no materia to unequip" << std::endl;
    // }
}

void Character::use(int idx, ICharacter& target) 
{
    if (idx >= 0 && idx < MAX_INV_SIZE && _inventory[idx])
        _inventory[idx]->use(target);
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
