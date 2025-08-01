/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:28:02 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/27 17:47:59 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToExec;
        const int _gradeToSign;

    public:
        AForm();
        AForm(std::string name, int gradeToExec, int gradeToSign);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        ~AForm();

        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToExec() const;
        int         getGradeToSign() const;

        void        beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif
