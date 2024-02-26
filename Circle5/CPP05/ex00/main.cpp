/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:33:20 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/26 10:43:32 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
	try
	{
		Bureaucrat b1 ( "B1", 1 );
		std::cout << b1;
		b1.incrementGrade ();
		std::cout << b1;
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}
	try
	{
		Bureaucrat b2 ( "B2", 150 );
		std::cout << b2;
		b2.decrementGrade ();
		std::cout << b2;
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what () << '\n';
	}
	try
	{
		Bureaucrat b3 ( "B3", 0 );
		std::cout << b3;
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what () << '\n';
	}
}