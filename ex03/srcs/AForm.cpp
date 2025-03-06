/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:18:10 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/24 16:28:26 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include <ostream>

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form not signed!";
}

AForm::AForm()
    : name("Default Form"), isSigned(false), signGrade(150), executeGrade(150) {
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : name(name), isSigned(false), signGrade(signGrade),
      executeGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1)
    throw GradeTooHighException();
  if (signGrade > 150 || executeGrade > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade),
      executeGrade(other.executeGrade) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    isSigned = other.isSigned;
  }
  return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getSignGrade() const { return signGrade; }

int AForm::getExecuteGrade() const { return executeGrade; }

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > signGrade)
    throw GradeTooLowException();
  isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << f.getName() << ", form is signed: " << f.getIsSigned()
     << ", sign grade: " << f.getSignGrade()
     << ", execute grade: " << f.getExecuteGrade() << ".";
  return os;
}
