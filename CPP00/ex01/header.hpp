/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:27:35 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/19 01:38:30 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

void check_input(std::string input, int *i);
std::string truncate(std::string str, size_t length, bool replace, std::string replacement);
#endif