/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:27:09 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 12:28:03 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &other);
        Cure &operator=(std::string const & type);
        ~Cure();
        Cure &operator=(const Cure &other);
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif // CURE_HPP