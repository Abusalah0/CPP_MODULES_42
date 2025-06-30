/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:35:06 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 01:05:07 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array 
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        unsigned int size() const;
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        class OutOfBoundsException : public std::exception 
        {
            public:
                const char* what() const throw();
        };
};

#include "Array.tpp"

#endif // ARRAY_HPP