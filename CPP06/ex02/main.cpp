/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:47:14 by abdsalah          #+#    #+#             */
/*   Updated: 2025/07/03 14:32:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base *generate(void)
{
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...) {}

    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...) {}

    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return ;
    }
    catch (...) {}
    std::cout << "Unknown Type" << std::endl;

}

int main( void ) 
{
    Base *base;
    
    srand(static_cast<unsigned int>(time(0)));
    base = generate();
    identify(base);
    identify(*base);
    
    delete base;
    return (0);
}