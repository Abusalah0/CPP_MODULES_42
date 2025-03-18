/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:53:58 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/19 00:08:04 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    public:
        void SetContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
        void printContact();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        void setFirstName(std::string first_name);
        void setLastName(std::string last_name);
        void setNickname(std::string nickname);
        void setPhoneNumber(std::string phone_number);
        void setDarkestSecret(std::string darkest_secret);
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;      
};

void Contact::printContact()
{
    std::cout << "First Name: " << getFirstName() << std::endl;
    std::cout << "Last Name: " << getLastName() << std::endl;
    std::cout << "Nickname: " << getNickname() << std::endl;
    std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}

void Contact::SetContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    setDarkestSecret(darkest_secret);
    setFirstName(first_name);
    setLastName(last_name);
    setNickname(nickname);
    setPhoneNumber(phone_number);
}
void Contact::setDarkestSecret (std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

void Contact::setFirstName (std::string first_name)
{
    this->first_name = first_name;
}

void Contact::setLastName (std::string last_name)
{
    this->last_name = last_name;
}

void Contact::setNickname (std::string nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber (std::string phone_number)
{
    this->phone_number = phone_number;
}

std::string Contact::getFirstName()
{
    return first_name;
}

std::string Contact::getLastName()
{
    return last_name;
}

std::string Contact::getNickname()
{
    return nickname;
}
std::string Contact::getPhoneNumber()
{
    return phone_number;
}
std::string Contact::getDarkestSecret()
{
    return darkest_secret;
}
#endif