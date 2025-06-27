/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:20:09 by abdsalah          #+#    #+#             */
/*   Updated: 2025/06/28 02:40:55 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
    private:
    
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        // Destructor
        ~Intern();
        
        AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif // INTERN_HPP