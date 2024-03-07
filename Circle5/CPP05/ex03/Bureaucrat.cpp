/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:31:51 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 08:09:11 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat ( std::string const name, int grade ) : _name ( name )
{
	if ( grade < 1 )
	{
		throw Bureaucrat::GradeTooHighException ();
	}
	else if ( grade > 150 )
	{
		throw Bureaucrat::GradeTooLowException ();
	}
	else
	{
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat ( Bureaucrat const &src ) : _name ( src._name )
{
	*this = src;
}

Bureaucrat::~Bureaucrat ()
{
}

Bureaucrat &Bureaucrat::operator= ( Bureaucrat const &rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::string const Bureaucrat::getName () const
{
	return this->_name;
}

int Bureaucrat::getGrade () const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade ()
{
	if ( this->_grade - 1 < 1 )
	{
		throw Bureaucrat::GradeTooHighException ();
	}
	else
	{
		this->_grade--;
	}
}

void Bureaucrat::decrementGrade ()
{
	if ( this->_grade + 1 > 150 )
	{
		throw Bureaucrat::GradeTooLowException ();
	}
	else
	{
		this->_grade++;
	}
}

void Bureaucrat::signAForm ( AForm &Aform )
{
	try
	{
		Aform.beSigned ( *this );
		std::cout << this->_name << " signs " << Aform.getName () << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cout << this->_name << " cannot sign " << Aform.getName () << " because " << e.what () << std::endl;
	}
}

void Bureaucrat::executeAForm ( AForm const &Aform ) const
{
	try
	{
		Aform.execute ( *this );
		std::cout << this->_name << " executes " << Aform.getName () << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cout << this->_name << " cannot execute " << Aform.getName () << " because " << e.what () << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what () const throw ()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what () const throw ()
{
	return "Grade is too low";
}

std::ostream &operator<< ( std::ostream &o, Bureaucrat const &rhs )
{
	o << rhs.getName () << ", bureaucrat grade " << rhs.getGrade ();
	return o;
}