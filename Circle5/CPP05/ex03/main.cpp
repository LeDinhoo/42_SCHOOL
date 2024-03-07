/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:20 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 09:38:59 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	try
	{
		std::cout << "Test 1" << std::endl;
		Intern zozioIntern;
		AForm *f1 = zozioIntern.makeForm ( "presidential pardon", "F1" );
		Bureaucrat b1 ( "B1", 1 );

		b1.signAForm ( *f1 );
		b1.executeAForm ( *f1 );
		delete f1;
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	std::cout << "\n";

	try
	{
		std::cout << "Test 2" << std::endl;
		Intern zozioIntern;
		AForm *f2 = zozioIntern.makeForm ( "wrongform", "F2" );
		Bureaucrat b2 ( "B2", 1 );

		b2.signAForm ( *f2 );
		b2.executeAForm ( *f2 );
		delete f2;
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	return ( 0 );
}