/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:57:35 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 01:32:55 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        
    public:
        // Constructors
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        
        // Destructor
        ~PresidentialPardonForm();
        
        // Assignment operator
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        
        // Member functions
        void execute(Bureaucrat const &executor) const;

};

#endif // PRESIDENTIALPARDONFORM_HPP