/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:18:59 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 09:29:51 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  public:
	Intern ();
	Intern ( Intern const &src );
	~Intern ();

	Intern &operator= ( Intern const &rhs );

	AForm *makeForm ( std::string const formName, std::string const target );

	class FormNotFoundException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};

  private:
	std::string _forms[3];
};

#endif