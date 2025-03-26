/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:45:30 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/27 02:30:13 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie =  zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return 0;
}