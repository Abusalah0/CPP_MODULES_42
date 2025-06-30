/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:30:43 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 01:01:34 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T> void iter(T *array, size_t length, void (*func)(T &))
{
    for (size_t i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T &))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif // ITER_HPP