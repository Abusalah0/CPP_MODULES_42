/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:39:44 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 13:51:50 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main( void )
{
    Intern intern;
    Bureaucrat boss(1, "Boss");
    Bureaucrat low(150, "Low");
    AForm* forms[3];

    forms[0] = intern.makeForm("ShrubberyCreationForm", "Garden");
    forms[1] = intern.makeForm("RobotomyRequestForm", "Robot");
    forms[2] = intern.makeForm("PresidentialPardonForm", "President");

    for (int i = 0; i < 3; i++)
    {
        if (!forms[i])
            continue ;
        low.signForm(*forms[i]);
        boss.signForm(*forms[i]);
        low.executeForm(*forms[i]);
        boss.executeForm(*forms[i]);
        
        delete forms[i];
    }
    AForm* unknown = intern.makeForm("UnknownForm", "Nobody");
    if (unknown)
        delete unknown;
    return (0);
}
