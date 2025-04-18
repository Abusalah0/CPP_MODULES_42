/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:03:57 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 01:41:09 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point( void );
        Point(const float x, const float y);
        Point(const Point &point);
        Point &operator=(const Point &point);
        ~Point( void );
        Fixed getX( void ) const;
        Fixed getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif // POINT_HPP