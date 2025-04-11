/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:15:35 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/03 22:24:57 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &other);
        virtual ~Animal();
        Animal &operator=(const Animal &other);
        virtual void makeSound() const;
        std::string getType() const;
        void setType(const std::string& type);
};

#endif // ANIMAL_HPP