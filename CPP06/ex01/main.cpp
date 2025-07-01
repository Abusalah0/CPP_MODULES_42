/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:53:41 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 15:30:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
    Data original;
    original.num = 42;
    original.str = "Hello, Serialization!";

    // Display original data
    std::cout << "=== Original Data ===" << std::endl;
    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << &original << std::endl;
    std::cout << "  num:     " << original.num << std::endl;
    std::cout << "  str:     " << original.str << std::endl;

    // Serialize the pointer to original data
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "\n=== Serialized Pointer Value ===" << std::endl;
    std::cout << "  Raw uintptr_t: " << raw << std::endl;

    // Deserialize the raw pointer back to Data pointer
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "\n=== Deserialized Data ===" << std::endl;
    std::cout << " Deserialized Data:" << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    std::cout << "  num:     " << deserialized->num << std::endl;
    std::cout << "  str:     " << deserialized->str << std::endl;

    // Check if the deserialized pointer matches the original pointer
    std::cout << "\n=== Pointer Check ===" << std::endl;
    if (deserialized == &original)
        std::cout << "Success: Deserialized pointer matches original!" << std::endl;
    else
        std::cout << "Error: Deserialized pointer does not match original!" << std::endl;

    return (0);
}
