/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:56:26 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 01:34:04 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        
    public:
        // Constructors
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        
        // Destructor
        ~RobotomyRequestForm();
        
        // Assignment operator
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        
        // member functions
        void execute(Bureaucrat const &executor) const;

};

#endif // ROBOTOMYREQUESTFORM_HPP