/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:14:15 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/08 06:56:45 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static inline std::string trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    
    if (start == std::string::npos)
        return "";
        
    size_t end = s.find_last_not_of(" \t\n\r");
    
    return s.substr(start, end - start + 1);
}

int checkHeader(const std::string &line, const std::string &delimiter)
{
    size_t pos;

    pos = line.find(delimiter);
    if (pos == std::string::npos)
    {
        return (1);
    }
    if (pos == 0 || pos == line.length() - 1)
    {
        std::cerr << "Error: Invalid header format." << std::endl;
        return (1);
    }

    std::string first = line.substr(0, pos);
    std::string second = line.substr(pos + delimiter.length());

    if (trim(first) == "")
    {
        std::cerr << "Error: First column cannot be empty." << std::endl;
        return (1);
    }
    if (trim(second) == "")
    {
        std::cerr << "Error: Second column cannot be empty." << std::endl;
        return (1);
    }
    return (0);
}

static bool validateInput(std::string &date, std::string &valueStr)
{
    if (!validateDate(date))
    {
        std::cerr << "Error: Invalid date format: " << date << " for line ";
        return (false);
    }
    if (!validateValue(valueStr))
    {
        return (false);
    }
    return (true);
}

bool validateValue(const std::string &valueStr)
{
    size_t dotCount;
    
    if (valueStr.empty())
    {
        std::cerr << "Error: Value cannot be empty.\n";
        return (false);
    }
    if (valueStr.find_first_not_of("-0123456789.") != std::string::npos)
    {
        std::cerr << "Error: use only digits and '.'\n";
        return (false);
    }
    dotCount = count(valueStr.begin(), valueStr.end(), '.');
    if (dotCount > 1)
    {
        std::cerr << "Error: too many '.' in value.\n";
        return (false);
    }
    if (dotCount == 1 && (valueStr.back() == '.' || valueStr.front() == '.'))
    {
        std::cerr << "Error: unexpected '.' in value.\n";
        return (false);
    }
    float value = std::stof(valueStr);
    if (value < 0.0f)
    {
        std::cerr << "Error: not a positive number.\n";
        return (false);
    }
    return (true);
}

bool validateDate(const std::string &date)
{
    int year;
    int month;
    int day;
    
    if (date.empty())
        return (false);
        
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);
        
    year = std::stoi(date.substr(0, 4));
    month = std::stoi(date.substr(5, 2));
    day = std::stoi(date.substr(8, 2));

    if (month < 1 || month > 12 || day < 1 || day > 31)
    
        return (false);

    if ((month == 2 && day > 29)
        ||(month == 2 && day == 29 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
        || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
    {
        return (false);
    }

    return (true);
}

static bool parseCsvLine(const std::string &line, std::string &date, std::string &valueStr)
{
    size_t sep;

    sep = line.find(',');
    if (sep == std::string::npos || sep == 0 || sep == line.length() - 1)
    {
        return (false); 
    }
    date = line.substr(0, sep);
    valueStr = line.substr(sep + 1);
    return (true);
}

int storeMap(std::map<std::string, float> &bitcoinData, std::ifstream &file)
{
    std::string     line;
    std::string     date;
    std::string     valueStr;
    float           value;
    
    getline(file, line);
    if (checkHeader(line, ","))
    {
        std::cerr << "Error: Invalid header format." << std::endl;
        return (1);
    }
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue ;
        if (!parseCsvLine(line, date, valueStr))
        {
            std::cerr << "Error: bad input => " << line << '.' << std::endl;
            continue ;
        }
        if (!validateInput(date, valueStr))
            continue ;
        value = stof(valueStr);
        bitcoinData[date] = value;
    }
    file.close();
    return (0);
}

int openFile(const std::string &filename, std::ifstream &file)
{
    file.open(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return (0);
    }
    return (1);
}

void calculateBitcoinValue(const std::map<std::string, float> &database, const std::string &date, float amount)
{
    float rate;
    
    if (amount > 1000.0f)
    {
        std::cerr << "Error: too large a number.\n";
        return ;
    }

    std::map<std::string, float>::const_iterator it = database.find(date);
    if (it == database.end())
    {
        it = database.lower_bound(date);
        if (it == database.begin())
        {
            std::cerr << "Error: no data available before " << date << "\n";
            return;
        }
        --it;
    }
    rate = it->second;
    std::cout << date << " => " << amount << " = " << rate * amount << "\n";
}

static bool parsePipeLine(const std::string &line, std::string &date, std::string &valueStr)
{
    
    size_t sep;
    
    sep = line.find('|');
    if (sep == std::string::npos || sep == 0 || sep == line.length() - 1)
        return (false);
        
    date = line.substr(0, sep);
    valueStr = line.substr(sep + 1);
    date = trim(date);
    valueStr = trim(valueStr);
    return (true);
}

int processInput(const std::map<std::string, float> &bitcoinData, std::ifstream &file)
{
    float       value;
    std::string line;
    std::string date;
    std::string valueStr;
    
    getline(file, line);

    if (checkHeader(line, " | "))
    {
        std::cerr << "Error: Invalid header format." << std::endl;
        return (1);
    }
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue ;
        if (!parsePipeLine(line, date, valueStr))
        {
            std::cerr << "Error: bad input => " << line << "\n";
            continue ;
        }
        if (!validateInput(date, valueStr))
            continue ;
        value = stof(valueStr);
        calculateBitcoinValue(bitcoinData, date, value);
    }
    return (0);
}
