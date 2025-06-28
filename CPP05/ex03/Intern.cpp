/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:20:16 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 14:25:36 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

Intern::Intern() {}

Intern::~Intern() {}

std::string strTolower(const std::string& str)
{
    std::string result;
    int i;
    
    i = 0;
    while (str[i])
    {
        result += std::tolower(str[i]);
        i++;
    }
    return (result);
}

int isValid(const std::string& formName)
{
    std::string name = strTolower(formName);

    std::string shrubberyForms[] = {
                    "shrubbery",
                    "shrubbery creation",
                    "shrubberycreation",
                    "shrubberycreationform"
                };

    std::string robotomyForms[] = {
                    "robotomy",
                    "robotomy request",
                    "robotomyrequest",
                    "robotomyrequestform"
                };

    std::string presidentialForms[] = {
                    "presidential",
                    "presidential pardon",
                    "presidentialpardon",
                    "presidentialpardonform"
                };

    
    for (int i = 0; i < 4; i++)
    {
        if (name == (shrubberyForms[i]))
        {
            return (1);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (name == (robotomyForms[i]))
        {
            return (2);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (name == (presidentialForms[i]))
        {
            return (3);
        }
    }

    return (0);
}

AForm* getForm(int formNum, std::string formTarget)
{
    if (formNum == 1)
    {
        return new ShrubberyCreationForm(formTarget);
    }
    else if (formNum == 2)
    {
        return new RobotomyRequestForm(formTarget);
    }
    else if (formNum == 3)
    {
        return new PresidentialPardonForm(formTarget);
    }
    else
        return (NULL);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    AForm* form = NULL;

    if (formName.empty())
    {
        std::cerr << "Error: Form name cannot be empty." << std::endl;
        return (NULL);
    }
    if (target.empty())
    {
        std::cerr << "Error: Target cannot be empty." << std::endl;
        return (NULL);
    }

    form = getForm(isValid(formName), target);
    if (form == NULL)
    {
        std::cerr << "Error: Form '" << formName << "' not recognized." << std::endl;
        return (NULL);
    }
    return (form);
}
