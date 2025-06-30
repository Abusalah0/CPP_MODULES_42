/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:25:34 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 00:27:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> T min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template <typename T> T max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

#endif // WHATEVER_HPP