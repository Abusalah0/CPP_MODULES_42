/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:24:32 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/25 22:41:34 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(int grade, std::string name);
        Bureaucrat(std::string name);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        
        Bureaucrat& operator=(const Bureaucrat& other);
        
        std::string getName() const;
        int     getGrade() const;
        void    setGrade(int grade);
        void    increment();
        void    decrement();
        void    signForm(Form &form);
        
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
          const char * what() const throw();
        };
};
    
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif //BUREAUCRAT_HPP