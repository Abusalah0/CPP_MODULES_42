/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 23:24:56 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/09 17:34:09 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

// thanks to Sebastian Lague
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    double A_x = a.getX().toFloat();
    double A_y = a.getY().toFloat();
    double B_x = b.getX().toFloat();
    double B_y = b.getY().toFloat();
    double C_x = c.getX().toFloat();
    double C_y = c.getY().toFloat();
    double P_x = point.getX().toFloat();
    double P_y = point.getY().toFloat();

    double denominator = ((B_y - C_y) * (A_x - C_x) + (C_x - B_x) * (A_y - C_y));
    if (denominator == 0)
    {
        std::cerr << "Error: Triangle is degenerate (area = 0)!" << std::endl;
        return false;
    }
    
    double aCoef = ((B_y - C_y) * (P_x - C_x) + (C_x - B_x) * (P_y - C_y)) / denominator;
    double bCoef = ((C_y - A_y) * (P_x - C_x) + (A_x - C_x) * (P_y - C_y)) / denominator;
    double cCoef = 1.0 - aCoef - bCoef;
    
    std::cout << "aCoef: " << aCoef << ", bCoef: " << bCoef << ", cCoef: " << cCoef << std::endl;
    
    return (aCoef >= 0 && bCoef >= 0 && cCoef >= 0);
}
