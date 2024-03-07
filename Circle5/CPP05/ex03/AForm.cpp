/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:09:54 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 07:02:49 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm () : _name ( "default" ), _gradeToSign ( 150 ), _gradeToExecute ( 150 )
{
	_signed = false;
}

AForm::AForm ( std::string const name, int gradeToSign, int gradeToExecute )
	: _name ( name ), _gradeToSign ( gradeToSign ), _gradeToExecute ( gradeToExecute )
{
	_signed = false;
	if ( gradeToSign < 1 || gradeToExecute < 1 )
	{
		throw AForm::GradeTooHighException ();
	}
	else if ( gradeToSign > 150 || gradeToExecute > 150 )
	{
		throw AForm::GradeTooLowException ();
	}
}

AForm::AForm ( AForm const &src )
	: _name ( src._name ), _gradeToSign ( src._gradeToSign ), _gradeToExecute ( src._gradeToExecute )
{
	_signed = src._signed;
	if ( _gradeToSign < 1 || _gradeToExecute < 1 )
	{
		throw AForm::GradeTooHighException ();
	}
	else if ( _gradeToSign > 150 || _gradeToExecute > 150 )
	{
		throw AForm::GradeTooLowException ();
	}
}

AForm::~AForm ()
{
}

AForm &AForm::operator= ( AForm const &rhs )
{
	if ( this != &rhs )
	{
		_signed = rhs._signed;
	}
	return ( *this );
}

std::string const AForm::getName () const
{
	return ( _name );
}

bool AForm::getSigned () const
{
	return ( _signed );
}

int AForm::getGradeToSign () const
{
	return ( _gradeToSign );
}

int AForm::getGradeToExecute () const
{
	return ( _gradeToExecute );
}

void AForm::beSigned ( Bureaucrat const &bureaucrat )
{
	if ( bureaucrat.getGrade () > _gradeToSign )
	{
		throw AForm::GradeTooLowException ();
	}
	else if ( _signed )
	{
		throw AForm::AFormAlreadySignedException ();
	}
	_signed = true;
}

const char *AForm::GradeTooHighException::what () const throw ()
{
	return ( "Grade is too high" );
}

const char *AForm::GradeTooLowException::what () const throw ()
{
	return ( "Grade is too low" );
}

const char *AForm::AFormAlreadySignedException::what () const throw ()
{
	return ( "AForm is already signed" );
}

const char *AForm::AFormNotSignedException::what () const throw ()
{
	return ( "AForm is not signed" );
}

std::ostream &operator<< ( std::ostream &o, AForm const &rhs )
{
	o << "AForm " << rhs.getName () << " is ";
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