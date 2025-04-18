/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:21:13 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 18:38:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
    type = "Dog";
    // std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
    // std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    // std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    // std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    // std::cout << "Woof Woof!" << std::endl;
}

std::string Dog::getIdea(int index) const
{
    if ( index < 100 && index >= 0)
    {
        return brain->ideas[index];
    }
    return "";
}

void Dog::setIdea(int index, const std::string &idea)
{
    if (index > -1 && index < 100)
    {
        brain->ideas[index] = idea;
    }
}

