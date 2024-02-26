/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:48:45 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/26 11:36:35 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form
{
  private:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

  public:
	Form ();
	Form ( std::string const name, int gradeToSign, int gradeToExecute );
	Form ( Form const &src );
	~Form ();

	Form &operator= ( Form const &rhs );

	std::string const getName () const;
	bool getSigned () const;
	int getGradeToSign () const;
	int getGradeToExecute () const;
	void beSigned ( Bureaucrat const &bureaucrat );

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

	class FormAlreadySignedException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};
};

std::ostream &operator<< ( std::ostream &o, Form const &rhs );

#endif