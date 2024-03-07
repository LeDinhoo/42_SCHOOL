/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:33:32 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 08:12:16 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm ( std::string const target )
	: AForm ( "PresidentialPardonForm", 25, 5 ), _target ( target )
{
}

PresidentialPardonForm::PresidentialPardonForm ( PresidentialPardonForm const &src )
	: AForm ( src ), _target ( src._target )
{
}

PresidentialPardonForm::~PresidentialPardonForm ()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator= ( PresidentialPardonForm const &rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
		this->_signed = rhs._signed;
	}
	return *this;
}

void PresidentialPardonForm::execute ( Bureaucrat const &executor ) const
{
	if ( this->getSigned () == false )
	{
		throw AForm::AFormNotSignedException ();
	}
	if ( executor.getGrade () > this->getGradeToExecute () )
	{
		throw AForm::GradeTooLowException ();
	}
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
