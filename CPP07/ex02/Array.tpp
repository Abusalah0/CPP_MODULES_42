/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:48:11 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/02 11:44:13 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) 
{
    if (n == 0)
    {
        _array = NULL;
    }
    else
    {
        _array = new T[n];
    }
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
    if (_size == 0)
    {
        _array = NULL;
    }
    else
    {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
        {
            _array[i] = other._array[i];
        }
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        if (_size == 0)
        {
            _array = NULL;
        }
        else
        {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
            {
                _array[i] = other._array[i];
            }
        }
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw IndexOutOfBoundsException();
    }
    return (_array[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
    {
        throw IndexOutOfBoundsException();
    }
    return (_array[index]);
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
    return ("Index out of bounds");
}

#endif // ARRAY_TPP