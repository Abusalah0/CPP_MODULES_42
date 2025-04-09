/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:41:39 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/09 13:53:35 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &other);
        ClapTrap(const std::string &name, int hitPoints, int energyPoints, int attackDamage);
        ClapTrap &operator=(const ClapTrap &other);
        virtual ~ClapTrap();
        
        virtual void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
