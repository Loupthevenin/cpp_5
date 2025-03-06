/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:36:41 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/05 14:42:02 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > getExecuteGrade())
    throw GradeTooLowException();

  std::cout << "Drilling noises..." << std::endl;
  srand(time(NULL));
  if (rand() % 2 == 0)
    std::cout << getName() << " has been successfully robotomized!"
              << std::endl;
  else
    std::cout << "Robotomy failed on " << getName() << "!" << std::endl;
}
