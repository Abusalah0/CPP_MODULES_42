/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:14:47 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/08 09:13:57 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    std::map<std::string, double> bitcoinData;
    std::ifstream file;
    std::ifstream dataBase;
    
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return (1);
    }
    if (!openFile(argv[1], file))
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return (1);
    }
    if (!openFile("data.csv", dataBase))
    {
        std::cerr << "Error: Could not open database file." << std::endl;
        return (1);
    }
    if (storeMap(bitcoinData, dataBase))
    {
        std::cerr << "Error: Could not store data from database." << std::endl;
        return (1);
    }
    if (processInput(bitcoinData, file))
        return (1);
    return (0);
}
