/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:14:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/02 11:55:32 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main( void )
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found value: " << *it << std::endl;

        easyfind(vec, 50);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    const std::vector<int> constVec = vec;
    try
    {
        std::vector<int>::const_iterator it2 = easyfind(constVec, 10);
        std::cout << "Found in const vector: " << *it2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
