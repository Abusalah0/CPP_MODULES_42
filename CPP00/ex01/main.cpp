/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:49:34 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/19 00:07:30 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"
#include "header.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string input;

    while (1)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, input);
        if (input == "EXIT")
            break;
        else if (input == "ADD")
            phoneBook.AddContact();
        else if (input == "SEARCH")
            phoneBook.SearchContact();
    }
    return 0;
}