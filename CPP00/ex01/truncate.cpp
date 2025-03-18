/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truncate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:25:12 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/19 00:05:37 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <iomanip>
#include "header.hpp"

std::string truncate(std::string str, size_t length, bool replace_last_char, std::string replacement)
{
    if (str.length() > length)
    {
        if (replace_last_char)
        {
            if (replacement.empty())
                return str.substr(0, length);
            if (replacement.length() > 1)
                return replacement.substr(0, length);
            return str.substr(0, length - 1) + replacement;
        }
        return str.substr(0, length - 1);
    }
    return str;
}
