/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:56:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 01:51:09 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 45, 72), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 45, 72), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    
    if (!getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeToExec())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises... " << std::endl;
    if (rand() % 2)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed for " << _target << "!" << std::endl;
    }
}
