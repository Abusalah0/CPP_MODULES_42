/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:39:44 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 02:41:06 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
    Intern intern;
    Bureaucrat boss(1, "Boss");
    Bureaucrat low(150, "Low");

    // Test known forms
    AForm* forms[3];
    forms[0] = intern.makeForm("ShrubberyCreationForm", "Garden");
    forms[1] = intern.makeForm("RobotomyRequestForm", "Robot");
    forms[2] = intern.makeForm("PresidentialPardonForm", "President");

    for (int i = 0; i < 3; i++)
    {
        if (!forms[i])
            continue;

        // Low grade tries to sign (should fail)
        low.signForm(*forms[i]);

        // Boss signs
        boss.signForm(*forms[i]);

        // Low grade tries to execute (should fail)
        low.executeForm(*forms[i]);

        // Boss executes (should succeed)
        boss.executeForm(*forms[i]);

        delete forms[i];
    }

    // Test unknown form
    AForm* unknown = intern.makeForm("UnknownForm", "Nobody");
    if (unknown)
        delete unknown;

    return 0;
}
