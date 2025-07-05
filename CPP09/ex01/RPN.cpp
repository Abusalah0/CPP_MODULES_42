/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:18:11 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/05 00:06:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <iostream>
#include <stack>

static bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool checkString(const std::string& expr)
{
    std::istringstream iss(expr);
    std::string token;
    
    while (iss >> token)
    {
        if (token.length() == 1 && (std::isdigit(token[0]) || isOperator(token[0])))
            continue;
        std:: cerr << "Invalid Tooooooookkkeen: \'"<< token[0]<< "\'" << std::endl;
        return (false);
    }
    return (true);
}

static bool applyOperator(std::stack<int>& s, char op)
{
    int b;
    int a;
    
    if (s.size() < 2)
    {
        std::cerr << "Error: insufficient operands." << std::endl;
        return (false);
    }
    
    b = s.top();
    s.pop();
    a = s.top();
    s.pop();
    
    if (op == '/' && b == 0)
    {
        std::cerr << "Error: division by zero." << std::endl;
        return (false);
    }
    switch (op)
    {
        case '+':
            s.push(a + b);
            break ;
        case '-':
            s.push(a - b);
            break ;
        case '*':
            s.push(a * b);
            break ;
        case '/':
            s.push(a / b);
            break ;
        default:
            return (false);
    }
    return (true);
}

int calcRpn(const std::string& expr)
{
    std::stack<int> s;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
        {
            s.push(token[0] - '0');
        }
        else if (token.length() == 1 && isOperator(token[0]))
        {
            if (!applyOperator(s, token[0]))
                return (1);
        }
    }
    if (s.size() != 1)
    {
        std::cerr << "Error: malformed expression." << std::endl;
        return (1);
    }
    std::cout << s.top() << std::endl;
    return (0);
}
