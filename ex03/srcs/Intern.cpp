/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:48:34 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/06 19:30:35 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm *createShrubbery(std::string const &target) {
  return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(std::string const &target) {
  return new RobotomyRequestForm(target);
}

AForm *createPresidential(std::string const &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
  int i;

  std::string formNames[] = {"shrubbery creation", "robotomy request",
                             "presidential pardon"};

  AForm *(*formCreators[])(std::string const &) = {
      createShrubbery, createRobotomy, createPresidential};

  i = 0;
  while (i < 3) {
    if (name == formNames[i]) {
      std::cout << "Intern creates " << name << std::endl;
      return formCreators[i](target);
    }
    i++;
  }
  std::cout << "Error: Form '" << name << "' does not exist!" << std::endl;
  return NULL;
}
