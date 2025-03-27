/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:24:45 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/27 04:41:37 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP


#include <iostream>

class Harl
{
    public:
        void complain( std::string level );
        
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif /* HARL_HPP */