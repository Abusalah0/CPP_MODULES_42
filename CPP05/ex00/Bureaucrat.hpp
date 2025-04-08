/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:24:32 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/08 18:13:23 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat : public std::exception
{
    private:
        const std::string _name;
        int               _grade;
    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(int grade, std::string name);
        Bureaucrat(std::string name);
        ~Bureaucrat();
        std::string getName() const;
        int     getGrade() const;
        void    setGrade(int grade);
        void    increment();
        void    decrement();
        class GradeTooHighException : public std::exception
        {
            const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception
        {
          const char * what() const noexcept override;
        };
};
    
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif //BUREAUCRAT_HPP