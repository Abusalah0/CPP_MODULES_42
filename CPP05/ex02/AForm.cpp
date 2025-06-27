/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:39:01 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/27 17:48:48 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("Form"), _isSigned(false), _gradeToExec(1), _gradeToSign(1) {}

AForm::AForm(std::string name, int gradeToExec, int gradeToSign)
    : _name(name), _isSigned(false), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
    if (gradeToExec < 1 || gradeToSign < 1)
        throw GradeTooHighException();
    if (gradeToExec > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToExec(other._gradeToExec),
      _gradeToSign(other._gradeToSign)
{}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToExec() const { return _gradeToExec; }
int AForm::getGradeToSign() const { return _gradeToSign; }

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << obj.getName()
        << ", form sign grade " << obj.getGradeToSign()
        << ", exec grade " << obj.getGradeToExec()
        << ", is signed: " << (obj.getIsSigned() ? "true" : "false");
    return (out);
}
