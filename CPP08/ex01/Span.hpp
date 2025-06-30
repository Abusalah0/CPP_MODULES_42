/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 02:23:58 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/01 02:47:44 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int _capacity;
    public:
        // Constructors, destructor, and assignment operator
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();
        Span &operator=(const Span &other);

        // Member functions
        void            addNumber(int number);
        void            addNumbers(const std::vector<int> &numbers);
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;
        unsigned int    size() const;
        unsigned int    capacity() const;
        bool            isFull() const;
        bool            isEmpty() const;
        std::vector<int> getNumbers() const;

        // Exception classes
        class FullSpanException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Span is full";
                }
        };

        class EmptySpanException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Span is empty";
                }
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Not enough numbers to calculate span";
                }
        };
    
};

#endif // SPAN_HPP