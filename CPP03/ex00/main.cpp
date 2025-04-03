/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:57:58 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 02:08:00 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap claptrap1;
    ClapTrap claptrap2(claptrap1);
    ClapTrap claptrap3;

    claptrap3 = claptrap1;

    claptrap1.attack("target1");
    claptrap2.takeDamage(5);
    claptrap3.beRepaired(3);

    return 0;
}