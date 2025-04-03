/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:35:52 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/03 19:35:52 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== Testing ClapTrap ===" << std::endl;
    ClapTrap clap1("Clappy");
    ClapTrap clap2(clap1); // Copy constructor
    ClapTrap clap3;
    clap3 = clap1;         // Assignment operator

    clap1.attack("Enemy");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    clap1.takeDamage(10);  // Should reduce HP to 0 (or below)
    clap1.attack("Another Enemy"); // Should fail because HP is 0
    clap1.beRepaired(5);   // Should also fail

    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    ScavTrap scav1("Scavvy");
    ScavTrap scav2(scav1); // Copy constructor

    scav1.attack("Villain");
    scav1.takeDamage(30);
    scav1.beRepaired(10);
    scav1.guardGate(); // Toggle guard mode (activate)
    scav1.guardGate(); // Toggle guard mode (deactivate)
    scav1.takeDamage(100); // Reduce HP to 0
    scav1.attack("Hero");  // Should fail
    scav1.beRepaired(10);  // Should fail
    scav1.guardGate();     // Should fail since HP is 0

    std::cout << "\n=== Testing FragTrap ===" << std::endl;
    FragTrap frag1("Fraggy");
    FragTrap frag2(frag1); // Copy constructor

    frag1.attack("Monster");
    frag1.takeDamage(50);
    frag1.beRepaired(20);
    frag1.highFivesGuys();
    frag1.takeDamage(100); // Reduce HP to 0
    frag1.attack("Final Boss"); // Should fail
    frag1.beRepaired(10);       // Should fail

    std::cout << "\n=== Testing DiamondTrap ===" << std::endl;
    DiamondTrap diamond1("Diamond");
    DiamondTrap diamond2(diamond1); // Copy constructor

    diamond1.attack("Bad Guy");
    diamond1.takeDamage(20);
    diamond1.beRepaired(15);
    diamond1.whoAmI(); // Display its own name and its ClapTrap name

    std::cout << "\n=== End of Testing ===" << std::endl;
    return 0;
}
