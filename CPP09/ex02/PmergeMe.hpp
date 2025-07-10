/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:19:27 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/10 12:47:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <cstdlib>
# include <string>
# include <climits>
# include <set>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        out << vec[i] << ' ';
    }
    return out;
}

void    checkInput(int ac, const char **argv, std::vector<int>& vec, std::deque<int>& deq);
void    mergeInsertSort(std::vector<int>& vec);
void    mergeInsertSort(std::deque<int>& deq);
#endif // PMERGEME_HPP