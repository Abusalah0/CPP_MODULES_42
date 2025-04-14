/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:10:08 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/14 11:53:08 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
  std::cout << "Brain default constructor called\n";
  for (int i = 0; i < 100; ++i)
    ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
  std::cout << "Brain copy constructor called\n";
  for (int i = 0; i < 100; ++i)
    ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = (&other)->ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain default destructor called" << std::endl;
}
