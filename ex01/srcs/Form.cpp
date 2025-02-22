/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:18:10 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/22 13:49:28 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include <ostream>

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

Form::Form()
    : name("Default Form"), isSigned(false), signGrade(150), executeGrade(150) {
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade),
      executeGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1)
    throw GradeTooHighException();
  if (signGrade > 150 || executeGrade > 150)
    throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade),
      executeGrade(other.executeGrade) {}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    isSigned = other.isSigned;
  }
  return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getSignGrade() const { return signGrade; }

int Form::getExecuteGrade() const { return executeGrade; }

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > signGrade)
    throw GradeTooLowException();
  isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << f.getName() << ", form is signed: " << f.getIsSigned()
     << ", sign grade: " << f.getSignGrade()
     << ", execute grade: " << f.getExecuteGrade() << ".";
  return os;
}
