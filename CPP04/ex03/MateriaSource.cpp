/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:44:04 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 18:11:02 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    // std::cout << "MateriaSource Default Constructor called" << '\n';
    for (int i = 0; i < 4; i++)
    {
        _materias[i] = NULL;
    }
}
MateriaSource::MateriaSource(const MateriaSource &other) 
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._materias[i])
            _materias[i] = other._materias[i]->clone();
        else
            _materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            delete _materias[i];
            if (other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
        return ;

    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = materia->clone();
            delete materia;
            // std::cout << "Learned materia of type: " << materia->getType() << std::endl;
            return ;
        }
    }
    // std::cout << "MateriaSource is full, cannot learn more materias." << std::endl;
    delete materia;
}


AMateria *MateriaSource::createMateria(std::string const &type)
{
     for (int i = 0; i < 4; i++)
     {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            return _materias[i]->clone();
        }
     }
    return (NULL);
}
