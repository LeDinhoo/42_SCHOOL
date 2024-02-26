/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:09:54 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/26 11:40:23 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form () : _name ( "default" ), _gradeToSign ( 150 ), _gradeToExecute ( 150 )
{
	_signed = false;
}

Form::Form ( std::string const name, int gradeToSign, int gradeToExecute )
	: _name ( name ), _gradeToSign ( gradeToSign ), _gradeToExecute ( gradeToExecute )
{
	_signed = false;
	if ( gradeToSign < 1 || gradeToExecute < 1 )
	{
		throw Form::GradeTooHighException ();
	}
	else if ( gradeToSign > 150 || gradeToExecute > 150 )
	{
		throw Form::GradeTooLowException ();
	}
}

Form::Form ( Form const &src )
	: _name ( src._name ), _gradeToSign ( src._gradeToSign ), _gradeToExecute ( src._gradeToExecute )
{
	_signed = src._signed;
	if ( _gradeToSign < 1 || _gradeToExecute < 1 )
	{
		throw Form::GradeTooHighException ();
	}
	else if ( _gradeToSign > 150 || _gradeToExecute > 150 )
	{
		throw Form::GradeTooLowException ();
	}
}

Form::~Form ()
{
}

Form &Form::operator= ( Form const &rhs )
{
	if ( this != &rhs )
	{
		_signed = rhs._signed;
	}
	return ( *this );
}

std::string const Form::getName () const
{
	return ( _name );
}

bool Form::getSigned () const
{
	return ( _signed );
}

int Form::getGradeToSign () const
{
	return ( _gradeToSign );
}

int Form::getGradeToExecute () const
{
	return ( _gradeToExecute );
}

void Form::beSigned ( Bureaucrat const &bureaucrat )
{
	if ( bureaucrat.getGrade () > _gradeToSign )
	{
		throw Form::GradeTooLowException ();
	}
	else if ( _signed )
	{
		throw Form::FormAlreadySignedException ();
	}
	_signed = true;
}

const char *Form::GradeTooHighException::what () const throw ()
{
	return ( "Grade is too high" );
}

const char *Form::GradeTooLowException::what () const throw ()
{
	return ( "Grade is too low" );
}

const char *Form::FormAlreadySignedException::what () const throw ()
{
	return ( "Form is already signed" );
}

std::ostream &operator<< ( std::ostream &o, Form const &rhs )
{
	o << "Form " << rhs.getName () << " is ";
	if ( rhs.getSigned () )
	{
		o << "signed";
	}
	else
	{
		o << "not signed";
	}
	o << " and requires grade " << rhs.getGradeToSign () << " to be signed and grade " << rhs.getGradeToExecute ()
	  << " to be executed";
	return ( o );
}