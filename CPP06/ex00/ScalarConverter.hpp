/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:34:09 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/30 21:37:02 by abdsalah         ###   ########.fr       */
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
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        virtual ~ScalarConverter() = 0;
    public:
        static void convert(const std::string &literal);

};

#endif // SCALARCONVERTER_HPP