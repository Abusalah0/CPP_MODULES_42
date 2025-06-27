/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:24:35 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 01:59:27 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (out);
}

Bureaucrat::Bureaucrat() : _name("give me a name please"), _grade(1)
{
    std::cout << "Bureaucrat constructor called" << std::endl;   
}

Bureaucrat::Bureaucrat(int grade) : _name("give me a name")
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(1) {}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;   
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    setGrade(other._grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Assignment Constructor was called.\n";
    if (this != &other)
    {
        _grade = other._grade;
    }
    return (*this);
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
    try
    {
        setGrade(this->_grade + 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}

void Bureaucrat::increment( void )
{
    try
    {
        setGrade(this->_grade - 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn’t sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
