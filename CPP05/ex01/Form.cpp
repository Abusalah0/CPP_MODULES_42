/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:39:01 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/25 22:40:00 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("Form"), _isSigned(false), _gradeToExec(1), _gradeToSign(1) {}

Form::Form(std::string name, int gradeToExec, int gradeToSign)
    : _name(name), _isSigned(false), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
    if (gradeToExec < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExec > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToExec(other._gradeToExec),
      _gradeToSign(other._gradeToSign)
{}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToExec() const { return _gradeToExec; }
int Form::getGradeToSign() const { return _gradeToSign; }

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << obj.getName()
        << ", form sign grade " << obj.getGradeToSign()
        << ", exec grade " << obj.getGradeToExec()
        << ", is signed: " << (obj.getIsSigned() ? "true" : "false");
    return (out);
}
