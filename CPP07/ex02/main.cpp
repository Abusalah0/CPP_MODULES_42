/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:33:30 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 01:15:32 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main( void )
{
    try {
        // Test constructors
        Array<int> defaultArr;
        std::cout << "Default array size: " << defaultArr.size() << '\n';

        std::cout << "Testing with a size of 5:" << std::endl;
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i;

        std::cout << "   Contents of intArray: ";
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        std::cout << "Testing copy constructor:" << '\n';
        Array<int> copyArray(intArray);
        std::cout << " Original intArray[0]: " << intArray[0] << std::endl;
        std::cout << " Copy copyArray[0]: " << copyArray[0] << std::endl;

        copyArray[0] = 999;
        std::cout << " After modification, intArray[0]: " << intArray[0] << std::endl;
        std::cout << " After modification, copyArray[0]: " << copyArray[0] << std::endl;    
        
        // Test assignment operator
        std::cout << "Testing assignment operator" << '\n';
        Array<int> assignArray;
        assignArray = intArray;
        
        std::cout << " Original intArray[1]: " << intArray[1] << std::endl;
        std::cout << " Assign assignArray[1]: " << assignArray[1] << std::endl;
        
        assignArray[1] = 888;
        std::cout << " After assignment, intArray[1]: " << intArray[1] << std::endl;
        std::cout << " After assignment, assignArray[1] = 888" << std::endl;
        
        // Test size method
        std::cout << "Trying to access out of bounds index:" << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << " Exception caught: " << e.what() << std::endl;
    }

    return (0);
}
