/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:48:45 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/26 11:36:35 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <fstream>

class AForm
{
  protected:
	std::string const _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

  public:
	AForm ();
	AForm ( std::string const name, int gradeToSign, int gradeToExecute );
	AForm ( AForm const &src );
	virtual ~AForm ();

	AForm &operator= ( AForm const &rhs );

	std::string const getName () const;
	bool getSigned () const;
	int getGradeToSign () const;
	int getGradeToExecute () const;
	void beSigned ( Bureaucrat const &bureaucrat );
	virtual void execute ( Bureaucrat const &executor ) const = 0;

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

	class AFormAlreadySignedException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};
	class AFormNotSignedException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};
};

std::ostream &operator<< ( std::ostream &o, AForm const &rhs );

#endif