/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:50:16 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/14 11:55:33 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRIAN_HPP
#define BRIAN_HPP

#include <iostream>

class Brain
{
    public :
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();
        std::string ideas[100];
};

#endif // BRIAN_HPP