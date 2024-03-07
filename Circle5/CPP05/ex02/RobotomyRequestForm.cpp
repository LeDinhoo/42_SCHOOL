/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:33:32 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 08:12:16 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm ( std::string const target )
	: AForm ( "RobotomyRequestForm", 72, 45 ), _target ( target )
{
}

RobotomyRequestForm::RobotomyRequestForm ( RobotomyRequestForm const &src ) : AForm ( src ), _target ( src._target )
{
}

RobotomyRequestForm::~RobotomyRequestForm ()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator= ( RobotomyRequestForm const &rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
		this->_signed = rhs._signed;
	}
	return *this;
}

void RobotomyRequestForm::execute ( Bureaucrat const &executor ) const
{
	if ( this->getSigned () == false )
	{
		throw AForm::AFormNotSignedException ();
	}
	if ( executor.getGrade () > this->getGradeToExecute () )
	{
		throw AForm::GradeTooLowException ();
	}
	srand ( time ( NULL ) );
	int rand = std::rand ();
	std::cout << "*Makes some drilling noises*" << std::endl;
	if ( rand % 2 == 0 )
	{
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << this->_target << " has failed to be robotomized" << std::endl;
	}
}
