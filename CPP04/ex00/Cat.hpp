/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:20:41 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/18 18:44:38 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &other);
        ~Cat();
        Cat &operator=(const Cat &other);
        void makeSound() const ;
};

#endif //CAT_HPP    