/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:30:40 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/27 02:25:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce();
        void setName(std::string name);
        std::string getName();
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif //ZOMBIE_HPP