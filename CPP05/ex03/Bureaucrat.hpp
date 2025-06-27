/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:24:32 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 01:51:59 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
        
    public:
        // constructors
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(int grade, std::string name);
        Bureaucrat(std::string name);
        Bureaucrat(const Bureaucrat& other);
        // destructor
        ~Bureaucrat();

        // assignment operator
        Bureaucrat& operator=(const Bureaucrat& other);
        
        // getters
        std::string     getName() const;
        int             getGrade() const;
        
        // setters
        void            setGrade(int grade);
        
        // member functions
        void            increment();
        void            decrement();
        void            signForm(AForm &form);
        void            executeForm(AForm const & form) const;

        // exception classes
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
          const char * what() const throw();
        };
};

// overloads
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif //BUREAUCRAT_HPP