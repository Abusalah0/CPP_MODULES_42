/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 04:24:35 by abdsalah          #+#    #+#             */
/*   Updated: 2025/03/27 04:44:43 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{

  Harl harl;
  if (argc != 2)
  {
    std::cout << "Usage: ./harl [DEBUG, INFO, WARNING, ERROR]" << std::endl;
    return 1;
  }
  
  harl.complain(argv[1]);
  return 0;
}