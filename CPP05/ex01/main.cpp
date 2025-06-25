/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:24:22 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/25 22:42:55 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    Bureaucrat bob(10, "Bob");
    Form formA("FormA", 20, 10);
    bob.signForm(formA);
    Bureaucrat joe(100, "Joe");
    Form formB("FormB", 50, 50);
    joe.signForm(formB);
    return 0;
}
