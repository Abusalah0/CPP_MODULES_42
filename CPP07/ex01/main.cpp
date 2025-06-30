/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:30:38 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 01:04:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(const T &element)
{
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element)
{
    element += 1;
}

int main( void )
{
    const std::string stringArray[] = {"this", "should", "be", "const"};
    int intArray[] = {1, 2, 3, 4, 5};
    
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    iter(intArray, intSize, incrementElement<int>);
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;

    size_t strSize = sizeof(stringArray) / sizeof(stringArray[0]);
    iter(stringArray, strSize, printElement<std::string>);
    std::cout << std::endl;
    return (0);
}
