/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheveni <ltheveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:54:55 by ltheveni          #+#    #+#             */
/*   Updated: 2025/03/06 19:36:45 by ltheveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"

int main(void) {
  Intern someRandomIntern;

  AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "RonRon");
  AForm *f2 = someRandomIntern.makeForm("robotomy request", "Dobby");
  AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Sirius");
  AForm *f4 = someRandomIntern.makeForm("????", "Nobody");

  Bureaucrat harry("harry", 1);

  f1->beSigned(harry);
  f1->execute(harry);

  f2->beSigned(harry);
  f2->execute(harry);

  f3->beSigned(harry);
  f3->execute(harry);

  (void)f4;
  delete f1;
  delete f2;
  delete f3;
  return 0;
}
