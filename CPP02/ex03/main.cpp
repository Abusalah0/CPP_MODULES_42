/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:00:45 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/09 17:54:54 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

// ai generated tests
void testTriangle(const Point &A, const Point &B, const Point &C, const Point &P, const std::string &desc)
{
    std::cout << "Test: " << desc << std::endl;
    bool inside = bsp(A, B, C, P);
    std::cout << "Point (" << P.getX().toFloat() << ", " << P.getY().toFloat() 
              << ") is " << (inside ? "inside" : "outside") << " the triangle." << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

int main(void)
{
    Point A(0.0f, 0.0f);
    Point B(10.0f, 30.0f);
    Point C(20.0f, 0.0f);

    Point inside(10.0f, 15.0f);
    testTriangle(A, B, C, inside, "Inside point (expected: inside)");

    Point outside(20.0f, 30.0f);
    testTriangle(A, B, C, outside, "Outside point (expected: outside)");

    Point onEdge(5.0f, 15.0f);
    testTriangle(A, B, C, onEdge, "Point on edge AB (expected: inside, or on boundary)");

    testTriangle(A, B, C, A, "Point on vertex A (expected: inside)");

    Point D(2.0f, 1.0f);
    Point E(8.0f, 5.0f);
    Point F(5.0f, 12.0f);
    Point inside2(5.0f, 6.0f);
    Point outside2(9.0f, 9.0f);
    testTriangle(D, E, F, inside2, "Inside point in rotated triangle (expected: inside)");
    testTriangle(D, E, F, outside2, "Outside point in rotated triangle (expected: outside)");

    Point G(0.0f, 0.0f);
    Point H(5.0f, 0.0f);
    Point I(10.0f, 0.0f);
    Point testPoint(5.0f, 0.0f);
    testTriangle(G, H, I, testPoint, "Degenerate triangle (collinear points)");

    return 0;
}
