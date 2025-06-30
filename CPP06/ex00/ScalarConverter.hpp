/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:34:09 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/30 21:10:57 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cerrno>

enum e_type {
    
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class ScalarConverter
{
    
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        virtual ~ScalarConverter() = 0;
        static void convert(const std::string &literal);

};

#endif // SCALARCONVERTER_HPP