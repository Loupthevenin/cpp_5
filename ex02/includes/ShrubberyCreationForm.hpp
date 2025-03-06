#pragma once

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm {
private:
  std::string target;

public:
  ShrubberyCreationForm(std::string const &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &executor) const;
};
