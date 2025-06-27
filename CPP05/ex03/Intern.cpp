/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:20:16 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 02:36:44 by abdsalah         ###   ########.fr       */
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
    
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return (result);
}

AForm* getForm(const std::string& formName, const std::string& target)
{
    std::string name = strTolower(formName);

    if (name.find("shrubbery") != std::string::npos)
    {
        return (new ShrubberyCreationForm(target));
    }
    else if (name.find("robotomy") != std::string::npos)
    {
        return (new RobotomyRequestForm(target));
    }
    else if (name.find("presidential") != std::string::npos)
    {
        return (new PresidentialPardonForm(target));
    }
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    AForm* form = nullptr;

    if (formName.empty())
    {
        std::cerr << "Error: Form name cannot be empty." << std::endl;
        return (nullptr);
    }
    if (target.empty())
    {
        std::cerr << "Error: Target cannot be empty." << std::endl;
        return (nullptr);
    }

    form = getForm(formName, target);
    if (form == nullptr)
    {
        std::cerr << "Error: Form '" << formName << "' not recognized." << std::endl;
        return (nullptr);
    }
    return (form);
}
