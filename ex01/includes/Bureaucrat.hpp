/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:51:08 by ltheveni          #+#    #+#             */
/*   Updated: 2025/02/22 13:41:54 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
private:
  std::string const name;
  int grade;

public:
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  std::string const &getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();

  void signForm(Form &form);

  friend std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
};
