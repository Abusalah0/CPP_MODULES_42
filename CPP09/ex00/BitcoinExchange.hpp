
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:14:14 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/06 20:04:32 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <algorithm>

bool    validateValue(const std::string &valueStr);
bool    validateDate(const std::string &date);
int     storeMap(std::map<std::string, float> &bitcoinData, std::ifstream &file);
int     openFile(const std::string &filename, std::ifstream &file);
int     processInput(const std::map<std::string, float> &bitcoinData, std::ifstream &file);

#endif // BITCOINEXCHANGE_HPP