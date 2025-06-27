/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:40:59 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/27 11:52:42 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

class Serializer {
    
    private:
        /* data */
    public:
        Serializer(/* args */);
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        static uintptr_t serialize(void *ptr);
        static void *deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP