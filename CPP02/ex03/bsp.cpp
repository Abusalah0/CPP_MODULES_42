/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 23:24:56 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/31 01:32:48 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>


// thanks to Sebastian Lague  
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
        float s1 = (c.getY() - a.getY()).toFloat();
        float s2 = (c.getX() - a.getX()).toFloat();
        float s3 = (b.getY() - a.getY()).toFloat();
        float s4 = (point.getY() - a.getY()).toFloat();

        double w1 = (a.getX().toFloat() * s1 + s4 * s2 - point.getX().toFloat() * s1) / (s3 * s2 - (b.getX() - a.getX()).toFloat() * s1);
        double w2 = (s4- w1 * s3) / s1;
        return w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1;
}