/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:18:20 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/05 14:10:20 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string name;
  bool isSigned;
  const int signGrade;
  const int executeGrade;

public:
  AForm();
  AForm(const std::string &name, int signGrade, int executeGrade);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    const char *what() const throw();
  };

  const std::string &getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;

  void beSigned(const Bureaucrat &b);

  virtual void execute(Bureaucrat const &executor) const = 0;

  friend std::ostream &operator<<(std::ostream &os, const AForm &f);
};
