/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 22:28:02 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 01:33:06 by abdsalah         ###   ########.fr       */
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
        // Constructors
        AForm();
        AForm(std::string name, int gradeToExec, int gradeToSign);
        AForm(const AForm& other);
        
        // Destructor
        virtual ~AForm();
        
        // Assignment operator
        AForm& operator=(const AForm& other);

        // Getters
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToExec() const;
        int         getGradeToSign() const;

        // member functions
        virtual void        beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        // exception classes
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
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };

};

// overloads
std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif
