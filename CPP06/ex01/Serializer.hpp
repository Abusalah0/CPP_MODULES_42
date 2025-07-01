/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:40:59 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 18:01:02 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "stdint.h"
#include "data.hpp"

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP