/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:34:08 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 17:55:31 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string &str)
{
    return (str.length() == 1 && !isdigit(str[0]));
}

static bool isInt(const std::string &str)
{
    char* end;
    long val;
    
    errno = 0;
    val = strtol(str.c_str(), &end, 10);
    
    return (*end == '\0' && errno != ERANGE
            && val >= std::numeric_limits<int>::min() 
            && val <= std::numeric_limits<int>::max()
        );
}

static bool isFloat(const std::string &str)
{
    char* end;

    if (str == "-inff" || str == "+inff" || str == "nanf")
        return (true);

    errno = 0;
    strtof(str.c_str(), &end);
    
    return (*end == 'f' && *(end + 1) == '\0' && errno == 0);
}

static bool isDouble(const std::string &str)
{
    char* end;
    
    if (str == "-inf" || str == "+inf" || str == "nan")
        return (true);
        
    errno = 0;
    strtod(str.c_str(), &end);
    
    return (*end == '\0' && errno != ERANGE);
}

static e_type detectType(const std::string &literal)
{
    if (isChar(literal))
        return (CHAR);
    if (isInt(literal))
        return (INT);
    if (isFloat(literal))
        return (FLOAT);
    if (isDouble(literal))
        return (DOUBLE);
        
    return (INVALID);
}
static void printChar(double value)
{
    std::cout << "char: ";
    
    if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
    }
    else if (!isprint(static_cast<int>(value)))
    {
        std::cout << "Non displayable" << std::endl;
    }
    else
    {
        std::cout << '\'' << static_cast<char>(value) << '\'' << std::endl;
    }
}

static void printInt(double value)
{
    std::cout << "int: ";
    
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
    std::cout << "float: ";
    
    if (std::isnan(value))
    {
        std::cout << "nanf" << std::endl;
    }
    else if (std::isinf(value))
    {
        if (value < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << "+inff" << std::endl;
    }
    else if (value < -std::numeric_limits<float>::max()
             || value > std::numeric_limits<float>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << static_cast<float>(value) << "f" << std::endl;
    }
}

static void printDouble(double value)
{
    std::cout << "double: ";
    
    if (std::isnan(value))
    {
        std::cout << "nan" << std::endl;
    }
    else if (std::isinf(value))
    {
        if (value < 0)
            std::cout << "-inf" << std::endl;
        else
            std::cout << "+inf" << std::endl;
    }
    else if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    e_type  type;
    double  value;
    
    type = detectType(literal);
    value = 0;

    switch (type)
    {
        case CHAR:
            value = static_cast<double>(literal[0]);
            break ;
        case INT:
            value = static_cast<double>(atoi(literal.c_str()));
            break ;
        case FLOAT:
            value = static_cast<double>(strtof(literal.c_str(), NULL));
            break ;
        case DOUBLE:
            value = strtod(literal.c_str(), NULL);
            break ;
        default:
            std::cerr << "Invalid literal" << std::endl;
            return ;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
