/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 05:03:28 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/27 01:24:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook()
{
}

PhoneBook::PhoneBook()
{
    index = 0;
    oldest = 0;
}

Contact PhoneBook::getContact(int index) 
{
    return contacts[index]; 
}

void PhoneBook::AddContact()
{
    std::string input[5];
    int targetIndex;
    const std::string fields[5] = {
                        "first name",
                        "last name", 
                        "nickname", 
                        "phone number", 
                        "darkest secret"
                    };
    for (int i = 0; i < 5; i++)
    {
        do
        {
            std::cout << "Enter the contact's " << fields[i] << ": ";
            std::getline(std::cin, input[i]);
            check_input(input[i], &i);
        } while (input[i].empty());
    }

    targetIndex = (index < 8) ? index : oldest;
    contacts[targetIndex].SetContact(input[0], input[1], input[2], input[3], input[4]);

    if (index < 8)
        index++;
    else
        oldest = (oldest + 1) % 8; 
}

void PhoneBook::SearchContact()
{
    std::string input;
    int idx;

    if (index == 0) 
    {
        std::cout << "PhoneBook is empty. Add contacts first!" << std::endl;
        return;
    }

    listContacts();    
    std::cout << "Enter the index of the contact you want to see: ";
    std::getline(std::cin, input);
    
    if (input.length() == 1 && isdigit(input[0])) 
    {
        idx = input[0] - '0';
        if (idx >= 0 && idx < index) 
        {
            contacts[idx].printContact();
            return ;
        }
    }
    std::cout << "Invalid index. Please try again." << std::endl;
}

void PhoneBook::listContacts()
{
    
    std::cout << std::right << std::setw(10) << "Index" << "|" 
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    for (int i = 0; i < index; i++) 
    {
        std::cout << std::right <<std::setw(10) << i << "|"
                  << std::setw(10) << truncate(getContact(i).getFirstName(), 10, 1, ".") << "|"
                  << std::setw(10) << truncate(getContact(i).getLastName(), 10, 1, ".") << "|"
                  << std::setw(10) << truncate(getContact(i).getNickname(), 10, 1, ".") << std::endl;
    }
}
