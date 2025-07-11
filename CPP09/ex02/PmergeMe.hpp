/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:19:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/11 12:08:15 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <cstdlib>
# include <climits>
# include <deque>
# include <iostream>
# include <set>
# include <string>
# include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        out << vec[i] << ' ';
    }
    return (out);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq)
{
    for (size_t i = 0; i < deq.size(); i++)
    {
        out << deq[i] << ' ';
    }
    return (out);
}

template<typename T>
void    fillMainChain(const T& container, T& mainChain, T& subChain, int& extraElement)
{
    int                 a, b;
    size_t              size = container.size();
    size_t              i; 
 
    extraElement = INT_MIN
    i = 0;
    while (i + 1 < size)
    {
        a = container[i];
        b = container[i + 1];
        if (a > b)
        {
            mainChain.push_back(b);
            subChain.push_back(a);
        }
        else
        {
            mainChain.push_back(a);
            subChain.push_back(b);
        }
        i += 2;
    }
    
    if (size % 2 != 0)
        extraElement = container[i];
}

template<typename T>
void binaryInsert(T& container, int value)
{
    typename T::iterator it = std::lower_bound(container.begin(), container.end(), value);
    container.insert(it, value);
}

void    checkInput(int ac, const char **argv, std::vector<int>& vec, std::deque<int>& deq);
void    mergeInsertSort(std::vector<int>& vec);
void    mergeInsertSort(std::deque<int>& deq);

#endif // PMERGEME_HPP