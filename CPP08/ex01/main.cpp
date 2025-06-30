/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:22:20 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 02:42:19 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

void printTestHeader(const std::string &title)
{
    std::cout << "\n=== " << title << " ===\n";
}

int main()
{
    try
    {
        printTestHeader("Basic Test");

        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        printTestHeader("Exception: Add number to full Span");

        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // Should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        printTestHeader("Exception: Shortest span with less than 2 elements");

        Span sp(5);
        sp.addNumber(42);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        printTestHeader("Bulk Add Numbers");

        Span sp(10);
        std::vector<int> batch;
        for (int i = 0; i < 7; ++i)
            batch.push_back(i * 10);

        sp.addNumbers(batch);
        std::cout << "Shortest Span after bulk insert: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span after bulk insert: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
    {
        printTestHeader("Large Test with 10,000 Numbers");

        Span sp(10000);
        std::srand(std::time(0));

        for (int i = 0; i < 10000; ++i)
            sp.addNumber(std::rand());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
