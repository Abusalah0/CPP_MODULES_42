/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:32:03 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/19 04:51:58 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void check_input(std::string input, int *i)
{
    if (input.empty())
    {
        std::cout << "Invalid input. Please try again." << std::endl;
        (*i)--;
    }
    else if (input == "EXIT")
        exit(0);
    if (*i == 0 || *i == 1 || *i == 2)
    {
        for (size_t j = 0; j < input.length(); j++)
        {
            if (!isalpha(input[j]) && !(input[j] == ' '))
            {
                std::cout << "Invalid input. Please try again." << std::endl;
                (*i)--;
                break;
            }
        }
    }
    else if (*i == 3)
    {
        for (size_t j = 0; j < input.length(); j++)
        {
            if (!isdigit(input[j]))
            {
                std::cout << "Invalid input. Please try again." << std::endl;
                (*i)--;
                break;
            }
        }
    }
}