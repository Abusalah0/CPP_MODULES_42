/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:27:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/03 05:28:07 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n=== Testing ClapTrap ===" << std::endl;
    
    ClapTrap clap1("Clappy");
    ClapTrap clap2(clap1); // Copy constructor
    ClapTrap clap3;
    
    clap3 = clap1; // Assignment operator
    
    clap1.attack("Enemy");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    
    clap1.takeDamage(10); // Should reach 0 HP
    clap1.attack("Another Enemy"); // Should fail
    clap1.beRepaired(5); // Should fail
    
    std::cout << "\n=== Testing ScavTrap ===" << std::endl;
    
    ScavTrap scav1("Scavvy");
    ScavTrap scav2(scav1);
    
    scav1.attack("Villain");
    scav1.takeDamage(30);
    scav1.beRepaired(10);
    
    scav1.guardGate(); // Activate guard mode
    scav1.guardGate(); // Deactivate guard mode
    
    scav1.takeDamage(100); // Should reach 0 HP
    scav1.attack("Hero"); // Should fail
    scav1.beRepaired(10); // Should fail
    scav1.guardGate(); // Should fail since 0 HP

    std::cout << "\n=== Testing FragTrap ===" << std::endl;

    FragTrap frag1("Fraggy");
    FragTrap frag2(frag1);
    
    frag1.attack("Monster");
    frag1.takeDamage(50);
    frag1.beRepaired(20);
    
    frag1.highFivesGuys();
    
    frag1.takeDamage(100); // Should reach 0 HP
    frag1.attack("Final Boss"); // Should fail
    frag1.beRepaired(10); // Should fail
    
    std::cout << "\n=== End of Testing ===" << std::endl;
    
    return 0;
}
