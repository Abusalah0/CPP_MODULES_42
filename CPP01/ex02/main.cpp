/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:34:59 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/27 04:23:44 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main(void)
{
    std::string str_var = "HI THIS IS BRAIN";
    std::string *stringPTR = &str_var;
    std::string &stringREF = str_var;

    std::cout << "Address in memory of the string: " << &str_var << std::endl;
    std::cout << "Address in memory of the stringPTR: " << stringPTR << std::endl;
    std::cout << "Address in memory of the stringREF: " << &stringREF << std::endl;
    std::cout << "StringPTR: " << *stringPTR << std::endl;
    std::cout << "StringREF: " << stringREF << std::endl;
    return 0;
}