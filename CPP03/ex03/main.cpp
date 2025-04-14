/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:35:52 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/12 12:02:16 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main( void )
{
    //clap    
    // ClapTrap clap1("clap");
    // ClapTrap clap2(clap1);
    // ClapTrap clap3;
    
    // clap3 = clap1;
    // clap1.attack("test clap 1");
    // clap1.takeDamage(5);
    // clap1.beRepaired(3);
    // clap1.takeDamage(10);
    // clap1.attack("test clap 2");
    // clap1.beRepaired(5);
    //scav
    // ScavTrap scav1("scav");
    // ScavTrap scav2(scav1);
    
    // scav1.attack("test scav 1");
    // scav1.takeDamage(30);
    // scav1.beRepaired(10);
    // scav1.guardGate();
    // scav1.guardGate();
    // scav1.takeDamage(100);
    // scav1.attack("test scav 2");
    // scav1.beRepaired(10);
    // scav1.guardGate();
    //frag
    // FragTrap frag1("frag");
    // FragTrap frag2(frag1);
    
    // frag1.attack("test frag 1");
    // frag1.takeDamage(50);
    // frag1.beRepaired(20);
    // frag1.highFivesGuys();
    // frag1.takeDamage(100);
    // frag1.attack("test frag 2");
    // frag1.beRepaired(10);
    //diamond
    DiamondTrap diamond1("Diamond");
    DiamondTrap diamond2(diamond1);

    diamond1.attack("test diamond 1");
    diamond1.takeDamage(20);
    diamond1.beRepaired(15);
    diamond1.whoAmI();

    return (0);
}
