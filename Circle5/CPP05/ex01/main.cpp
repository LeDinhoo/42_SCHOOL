/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:20 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/26 11:39:36 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	Bureaucrat b1 ( "B1", 1 );
	Bureaucrat b2 ( "B2", 150 );
	Form f1 ( "F1", 1, 1 );
	Form f2 ( "F2", 150, 150 );

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << "\n";

	try
	{
		Form f3 ( "F3", 0, 1 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	try
	{
		Form f4 ( "F4", 1, 0 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	try
	{
		Form f5 ( "F5", 151, 1 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	try
	{
		Form f6 ( "F6", 1, 151 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	try
	{
		Form f7 ( "F7", 150, 1 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	try
	{
		Form f8 ( "F8", 1, 150 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	try
	{
		Form f9 ( "F9", 150, 150 );
		b1.signForm ( f9 );
		b2.signForm ( f9 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	try
	{
		Form f10 ( "F10", 1, 1 );
		b2.signForm ( f10 );
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	return ( 0 );
}