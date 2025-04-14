/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:57:58 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/12 11:54:38 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
    //clap
    // ClapTrap clap1("clap");
    // ClapTrap clap2(clap1);
    // ClapTrap clap3;
    
    // clap3 = clap1;
    // clap1.attack("first");
    // clap1.takeDamage(5);
    // clap1.beRepaired(3);
    // clap1.takeDamage(10);
    // clap1.attack("second");
    // clap1.beRepaired(5);
    //scav    
    ScavTrap scav1("scav");
    ScavTrap scav2(scav1);
    
    scav1.attack("test scav 1");
    scav1.takeDamage(30);
    scav1.beRepaired(10);
    scav1.guardGate();
    scav1.guardGate();
    scav1.takeDamage(100);
    scav1.attack("test scav 2");
    scav1.beRepaired(10);
    scav1.guardGate();
    
    return (0);
}
