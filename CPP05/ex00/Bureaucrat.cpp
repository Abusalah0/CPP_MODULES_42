/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:24:35 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/08 18:14:22 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return (out);
}

Bureaucrat::Bureaucrat() : _name("give me a name please"), _grade(1)
{
    std::cout << "Bureaucrat constructor calld" << std::endl;   
}

Bureaucrat::Bureaucrat(int grade) : _name("give me a name")
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(int grade, std::string name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name): _grade(1), _name(name)
{
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor calld" << std::endl;   
}

std::string Bureaucrat::getName( void ) const
{
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (this->_grade);
}

void Bureaucrat::decrement( void )
{
    setGrade(this->_grade + 1);
}

void Bureaucrat::increment( void )
{
    setGrade(this->_grade - 1);
}

void Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
    else if (grade < 1)
    {
        throw GradeTooHighException();
    }
    this->_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "grade too low";
}
