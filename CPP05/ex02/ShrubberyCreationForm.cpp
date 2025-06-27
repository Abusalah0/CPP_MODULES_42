/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:54:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 01:52:44 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 137, 145), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 137, 145), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeToExec())
        throw AForm::GradeTooLowException();

    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs.is_open())
        throw std::runtime_error("Failed to open file for writing");

    ofs << "                   ,@@@@@@@,\n";
    ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
    ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
    ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
    ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
    ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
    ofs << "       |o|        | |         | |\n";
    ofs << "       |.|        | |         | |\n";
    ofs << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
    ofs.close();
}
