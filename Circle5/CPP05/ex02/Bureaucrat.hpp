/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:26:36 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 07:55:31 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
  private:
	std::string const _name;
	int _grade;

  public:
	Bureaucrat ( std::string const name, int grade );
	Bureaucrat ( Bureaucrat const &src );
	~Bureaucrat ();

	Bureaucrat &operator= ( Bureaucrat const &rhs );

	std::string const getName () const;
	int getGrade () const;
	void incrementGrade ();
	void decrementGrade ();
	void signAForm ( AForm &Aform );
	void executeAForm ( AForm const &Aform ) const;

	class GradeTooHighException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};

	class GradeTooLowException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};
};

std::ostream &operator<< ( std::ostream &o, Bureaucrat const &rhs );

#endif