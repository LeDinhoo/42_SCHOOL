/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:20 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 09:17:34 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	Bureaucrat b1 ( "B1", 145 );
	Bureaucrat b2 ( "B2", 137 );

	ShrubberyCreationForm f1 ( "F1" );
	RobotomyRequestForm f2 ( "F2" );
	PresidentialPardonForm f3 ( "F3" );

	try
	{
		b1.signAForm ( f1 );
		b1.executeAForm ( f1 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	std::cout << "\n";

	try
	{
		b2.signAForm ( f1 );
		b2.executeAForm ( f1 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	std::cout << "\n";
	Bureaucrat b3 ( "B3", 72 );
	Bureaucrat b4 ( "B4", 45 );

	try
	{
		b3.signAForm ( f2 );
		b3.executeAForm ( f2 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	std::cout << "\n";
	try
	{
		b4.signAForm ( f2 );
		b4.executeAForm ( f2 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	Bureaucrat b5 ( "B5", 25 );
	Bureaucrat b6 ( "B6", 5 );

	std::cout << "\n";
	try
	{
		b5.signAForm ( f3 );
		b5.executeAForm ( f3 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	std::cout << "\n";

	try
	{
		b6.signAForm ( f3 );
		b6.executeAForm ( f3 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	return ( 0 );
}