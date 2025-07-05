/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:22:20 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/04 23:54:42 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"3 4 + 2 3 * ...\"" << std::endl;        
        return (1);
    }
    if (!checkString(argv[1]))
    {
        return (1);
    }
    if (calcRpn(argv[1]))
    {
        return (1);
    }
    return (0);
}
