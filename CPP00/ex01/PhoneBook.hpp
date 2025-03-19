/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:22:49 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/19 05:07:24 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "header.hpp"

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        void AddContact();
        void SearchContact();
        Contact getContact(int index) { return contacts[index]; }
        void listContacts();
    private:
        Contact contacts[8];
        int index;
        int oldest;
};

#endif // PHONEBOOK_HPP