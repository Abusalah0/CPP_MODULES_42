/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:22:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/14 17:05:03 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
    Animal* animals[4];
    
    for (int i = 0; i < 2; ++i)
    {
        std::cout << "creating Animal number " << i << " of type Dog" << std::endl;
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    Dog* originalDog = static_cast<Dog*>(animals[0]);
    originalDog->setIdea(0, "Chase the mailman");
    std::cout << "Original Dog idea[0]: " 
              << originalDog->getIdea(0) << std::endl;

    std::cout << "original dog type = " 
              << originalDog->getType() << std::endl;

    Dog* copiedDog = new Dog(*originalDog);
    std::cout << "Copied   Dog idea[0]: " 
              << copiedDog->getIdea(0) << std::endl;

    copiedDog->setIdea(0, "Eat the homework");
    std::cout << "After modifying copy:" << std::endl;
    std::cout << "  Original Dog idea[0]: " 
              << originalDog->getIdea(0) << std::endl;
    std::cout << "  Copied   Dog idea[0]: " 
              << copiedDog->getIdea(0) << std::endl;
              
    delete copiedDog;
    for (int i = 0; i < 4; ++i)
        delete animals[i];
    return (0);
}
