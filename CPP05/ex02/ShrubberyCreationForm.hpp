/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:54:00 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 01:32:46 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        
    public:
        // Constructors
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        
        // Destructor
        ~ShrubberyCreationForm();
        
        // Assignment operator
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        
        // Member functions
        void execute(Bureaucrat const &executor) const;

};



#endif // SHRUBBERYCREATIONFORM_HPP