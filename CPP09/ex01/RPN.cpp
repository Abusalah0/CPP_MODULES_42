/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:18:11 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/03 13:11:17 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool checkString(std::string expr)
{
    for (size_t i = 0; i < expr.length(); ++i)
    {
        if (expr[i] != ' ' && !isdigit(expr[i]) && !isOperator(expr[i]))
            return (false);
    }
    return (true);
}

int calcRpn(std::string expr)
{
    std::stack<char> s;
    int a;
    int b;
    int c;
    
    if (!checkString(expr))
    {
        return (-1);
    }
    
    for (size_t i = 0; i < expr.length(); i++)
    {
        if (isdigit(expr[i]))
            s.push(expr[i]);
        else if (isOperator(expr[i]))
        {
            a = s.top() - 48;
            s.pop();
            b = s.top() - 48;
            s.pop();
            switch (expr[i])
            {
                case '*':
                    c = a * b;
                    break ;
                case '/':
                    c = a / b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '+':
                    c = a + b;
                    break;
                default:
                    break;
            }       
        }
    }
    return (0);    
}