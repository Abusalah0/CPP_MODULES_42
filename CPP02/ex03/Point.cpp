/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 22:04:07 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/30 23:34:12 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0)
{
    
}

Point:: Point (const float x, const float y) : x(x), y(y)
{
    
}
Point ::Point (const Point &point) : x(point.x), y(point.y)
{
    
}

Point &Point::operator=(const Point &point)
{
    if (this != &point)
    {
        const_cast<Fixed&>(x) = point.x;
        const_cast<Fixed&>(y) = point.y;
    }
    return *this;
}
Point::~Point()
{
    
}
Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}

