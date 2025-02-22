/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:51:06 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/22 10:58:06 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <ostream>

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
  this->grade = grade;
}

std::string const &Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
  if (grade - 1 < 1)
    throw GradeTooHighException();
  grade--;
}

void Bureaucrat::decrementGrade() {
  if (grade + 1 > 150)
    throw GradeTooLowException();
  grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
  return os;
}
