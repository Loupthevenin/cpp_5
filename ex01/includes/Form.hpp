/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:18:20 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/22 13:49:19 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
private:
  const std::string name;
  bool isSigned;
  const int signGrade;
  const int executeGrade;

public:
  Form();
  Form(const std::string &name, int signGrade, int executeGrade);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  const std::string &getName() const;
  bool getIsSigned() const;
  int getSignGrade() const;
  int getExecuteGrade() const;

  void beSigned(const Bureaucrat &b);

  friend std::ostream &operator<<(std::ostream &os, const Form &f);
};
