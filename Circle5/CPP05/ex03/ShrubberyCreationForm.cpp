/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:33:32 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 08:12:16 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm ( std::string const target )
	: AForm ( "ShrubberyCreationForm", 145, 137 ), _target ( target )
{
}

ShrubberyCreationForm::ShrubberyCreationForm ( ShrubberyCreationForm const &src )
	: AForm ( src ), _target ( src._target )
{
}

ShrubberyCreationForm::~ShrubberyCreationForm ()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= ( ShrubberyCreationForm const &rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
		this->_signed = rhs._signed;
	}
	return *this;
}

void ShrubberyCreationForm::execute ( Bureaucrat const &executor ) const
{
	if ( this->getSigned () == false )
	{
		throw AForm::AFormNotSignedException ();
	}
	if ( executor.getGrade () > this->getGradeToExecute () )
	{
		throw AForm::GradeTooLowException ();
	}
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file ( filename.c_str () );
	if ( file.is_open () )
	{
		file << "     /\\*\\     " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||        ||" << std::endl;
		file << "      ||        ||" << std::endl;
		file << "      ||        ||" << std::endl;
		file << std::endl;
		file.close ();
	}
	else
	{
		std::cerr << "Error: could not create file" << std::endl;
	}
}
