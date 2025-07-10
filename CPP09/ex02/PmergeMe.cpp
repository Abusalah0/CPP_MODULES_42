/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:19:28 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/10 15:37:04 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkInt(const std::string& num)
{
    size_t  i = 0;
    long    l;
    
    if (num.empty())
        return (false);
    if (num[0] == '+')
    {
        if (num.length() == 1)
        {
            std::cerr << "Invalid input: '" << num << "'" << std::endl;
            return (false);
        }
        i++;
    }
    for (; i < num.length(); ++i)
    {
        if (!std::isdigit(num[i]))
        {
            std::cerr << "Invalid character: '" << num[i] << "'" << std::endl;
            return (false);
        }
    }
    
    l = std::atol(num.c_str());
    if (l > INT_MAX)
    {
        std::cerr << "Integer too large: " << num << std::endl;
        return (false);
    }
    return (true);
}

void checkInput(int ac, const char **av, std::vector<int>& vec, std::deque<int>& deq)
{
    std::set<int> set;
    int value;
    
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integers...>" << std::endl;
        exit(1);
    }

    for (int i = 1; i < ac; ++i)
    {
        std::string arg(av[i]);
        if (!checkInt(arg))// validate each arg
            exit(1);

        value = std::atoi(av[i]);
        if (set.find(value) != set.end())// check for duplicates
        {
            std::cerr << "Duplicate value: " << value << std::endl;
            exit(1);
        }
        set.insert(value);
        vec.push_back(value);
        deq.push_back(value);
    }
}

void mergeInsertSort(std::vector<int>& vec)
{
    int                 i, a, b;
    int                 extraElement = INT_MIN;
    int                 size = vec.size();
    std::vector<int>    mainChain;
    std::vector<int>    subChain;
    
    if (vec.size() <= 1)
        return ;
    
    i = 0;
    while (i + 1< vec.size())
    {
        a = vec[i];
        b = vec[i + 1];
        if (a > b)
        {
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
        }
        i += 2;
    }
    
    if (size % 2 != 0)
    {
        extraElement = vec[i];
    }

    mergeInsertSort(mainChain);
    
}

void mergeInsertSort(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return ;
    
}