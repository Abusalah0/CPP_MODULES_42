/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:44:40 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/27 11:46:34 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

class Base {
    public:
        Base();
        Base(const Base &other);
        Base &operator=(const Base &other);
        virtual ~Base() = 0; // Pure virtual destructor
};

#endif // BASE_HPP