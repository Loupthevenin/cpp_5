/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:54:55 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/22 11:02:58 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void) {
  try {
    Bureaucrat harry("Harry", 2);
    std::cout << harry << std::endl;

    harry.incrementGrade();
    std::cout << "After incrementGrade: " << harry << std::endl;
    harry.incrementGrade();
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  try {
    Bureaucrat ron("Ron", 150);
    std::cout << ron << std::endl;

    ron.decrementGrade();
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  return 0;
}
