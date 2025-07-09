/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:19:28 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/09 17:37:17 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T> void printVec(std::vector<T> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}

bool    checkInt(std::string num)
{
    size_t  i;
    long    l;
    
    i = 0;
    if (num.length() > 10)
    {
        std::cout << num << "length " << num.length() << std::endl;
        return (false);
    }
    if (num[0] == '+') 
        i++;
    for (; i < num.length(); i++)
    {
        if (!isdigit(num[i]))
        {
            std::cout << num[i] << " not a digit."  << std::endl;
            return (false);
        }
    }
    l = std::atol(num.c_str());
    if (l > INT_MAX || l < INT_MIN)
    {
        std::cout << num << " too large."  << std::endl;
        return (false);        
    }
    return (true);
}

static void checkDup(std::vector<int> )
{
    
}

void    checkInput(int ac, const char **av, std::vector<int> vec, std::deque<int> deq)
{
    if (ac < 2)
    {
        std::cerr << "can't run without args.\n";
        std::cerr << "Usage: ./PmergeMe 2 3 41 5 ..." << std::endl;
        exit(1);
    }
    // check each int
    for (int i = 1; i < ac; i++)
    {
        if (!checkInt(av[i]))
            exit(1);
    }
    for (int i = 1; i < ac; i++)
    {
        vec.push_back(std::atoi(av[i]));
        deq.push_back(std::atoi(av[i]));
    }
    std::vector<int> copy_vec = vec;
    checkDup(copy_vec);
}
