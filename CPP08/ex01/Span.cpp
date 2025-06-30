/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:22:31 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 02:47:37 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <vector>
#include <algorithm>

Span::Span() : _capacity(0) {}

Span::Span(unsigned int n) : _capacity(n) {}

Span::Span(const Span &other) : _numbers(other._numbers), _capacity(other._capacity) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _capacity = other._capacity;
    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (isFull())
        throw FullSpanException();
    _numbers.push_back(number);
}

void Span::addNumbers(const std::vector<int> &numbersToAdd)
{
    if (isFull())
        throw FullSpanException();
    if (_numbers.size() + numbersToAdd.size() > _capacity)
        throw FullSpanException();
    _numbers.insert(_numbers.end(), numbersToAdd.begin(), numbersToAdd.end());
}

unsigned int Span::shortestSpan() const
{
    unsigned int min;
    unsigned int current;  
    std::vector<int> sortedNumbers;
    std::vector<int>::const_iterator it;
    
    if (isEmpty())
        throw EmptySpanException();
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    it = sortedNumbers.begin();
    
    min = static_cast<unsigned int>(*(it + 1) - *it);

    for (; it != sortedNumbers.end() - 1; ++it)
    {
        current = static_cast<unsigned int>(*(it + 1) - *it);
        if (current < min)
            min = current;
    }
    return (min);
}

unsigned int Span::longestSpan() const
{
    int minNumber;
    int maxNumber;
    
    if (isEmpty())
        throw EmptySpanException();
    if (_numbers.size() < 2)
        throw NotEnoughNumbersException();

    minNumber = *std::min_element(_numbers.begin(), _numbers.end());
    maxNumber = *std::max_element(_numbers.begin(), _numbers.end());
    return (static_cast<unsigned int>(maxNumber - minNumber));
}

unsigned int Span::size() const
{
    return (_numbers.size());
}

unsigned int Span::capacity() const
{
    return (_capacity);
}

bool Span::isFull() const
{
    return (_numbers.size() >= _capacity);
}

bool Span::isEmpty() const
{
    return (_numbers.empty());
}

std::vector<int> Span::getNumbers() const
{
    return (_numbers);
}
