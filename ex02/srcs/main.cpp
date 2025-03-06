/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:54:55 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/06 18:44:45 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>

void test_shrubbery() {
  std::cout << "==========SHRUBBERY==========" << std::endl;
  try {
    Bureaucrat harry("harry", 1);
    Bureaucrat neville("neville", 140);
    ShrubberyCreationForm terrier("Terrier");

    std::cout << terrier << std::endl;

    harry.executeForm(terrier);
    harry.signForm(terrier);
    harry.executeForm(terrier);
    neville.executeForm(terrier);
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
}

void test_robotomy() {
  std::cout << "==========ROBOTOMY==========" << std::endl;
  try {
    Bureaucrat harry("harry", 1);
    RobotomyRequestForm croutard("croutard");

    harry.executeForm(croutard);
    harry.signForm(croutard);
    harry.executeForm(croutard);
    harry.executeForm(croutard);
    harry.executeForm(croutard);
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
}

void test_presidential() {
  std::cout << "==========PRESIDENTIAL==========" << std::endl;
  try {
    Bureaucrat harry("harry", 6);
    PresidentialPardonForm belatrix("belatrix");

    harry.executeForm(belatrix);
    harry.signForm(belatrix);
    harry.executeForm(belatrix);
    harry.incrementGrade();
    harry.executeForm(belatrix);
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
}

int main(void) {
  test_shrubbery();
  test_robotomy();
  test_presidential();
  return 0;
}
