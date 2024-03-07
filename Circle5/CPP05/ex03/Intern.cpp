/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:20:04 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 09:40:35 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern ()
{
	this->_forms[0] = "shrubbery creation";
	this->_forms[1] = "robotomy request";
	this->_forms[2] = "presidential pardon";
}

Intern::Intern ( Intern const &src )
{
	*this = src;
}

Intern::~Intern ()
{
}

Intern &Intern::operator= ( Intern const &rhs )
{
	if ( this != &rhs )
	{
		for ( int i = 0; i < 3; i++ )
		{
			this->_forms[i] = rhs._forms[i];
		}
	}
	return ( *this );
}

AForm *Intern::makeForm ( std::string const formName, std::string const target )
{
	int i = 0;

	for ( i = 0; i < 3; i++ )
	{
		if ( formName == _forms[i] )
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			break;
		}
	}
	switch ( i )
	{
	case 0:
		return ( new ShrubberyCreationForm ( target ) );
	case 1:
		return ( new RobotomyRequestForm ( target ) );
	case 2:
		return ( new PresidentialPardonForm ( target ) );
	default:
		throw Intern::FormNotFoundException ();
	}
}

const char *Intern::FormNotFoundException::what () const throw ()
{
	return ( "Form not found" );
}