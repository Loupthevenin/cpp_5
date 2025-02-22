/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:54:55 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/22 13:54:42 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <exception>
#include <iostream>

int main(void) {
  try {
    Bureaucrat harry("Harry", 5);
    Bureaucrat ron("Ron", 100);

    Form contract("Poudlard", 10, 50);
    Form topsecret("Topsecret", 2, 5);

    std::cout << contract << std::endl;
    std::cout << topsecret << std::endl;

    harry.signForm(contract);
    ron.signForm(topsecret);
    harry.signForm(topsecret);

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
