/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:32:36 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/10 19:59:15 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
        std::vector<int> vec;
        std::deque<int> que;
        
        
        checkInput(argc, argv, vec, que);
        std::cout << "Before: " << vec << std::endl;
        
        clock_t vecStart = clock();
        mergeInsertSort(vec);
        clock_t vecEnd = clock();
        
        clock_t queStart = clock();
        mergeInsertSort(que);
        clock_t queEnd = clock();
        
        std::cout << "After: " << vec << std::endl;

        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
                << static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;
        std::cout << "Time to process a range of " << que.size() << " elements with std::deque: "
                << static_cast<double>(queEnd - queStart) / CLOCKS_PER_SEC * 1000 << " ms" << std::endl;

        std::cout << vec << std::endl;
        return (0);
}
