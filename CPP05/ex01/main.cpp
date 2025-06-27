/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:24:22 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/27 17:47:59 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    Bureaucrat bob(10, "Bob");
    AForm formA("FormA", 20, 10);
    bob.signForm(formA);
    Bureaucrat joe(100, "Joe");
    AForm formB("FormB", 50, 50);
    joe.signForm(formB);
    return 0;
}
