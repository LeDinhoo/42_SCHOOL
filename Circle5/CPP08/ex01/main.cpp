/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:46:41 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/11 14:51:29 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main ()
{
	std::cout << "\n\nTEST 1" << std::endl;
	Span Tab ( 9 );
	try
	{
		for ( int i = 0; i < 9; i++ )
		{
			Tab.addNumber ( i * 50 );
			std::cout << "Tab[" << i << "] = " << i << std::endl;
		}
		std::cout << "The shortest span is : " << Tab.shortestSpan () << std::endl;
		std::cout << "The longest span is : " << Tab.longestSpan () << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what () << std::endl;
	}

	std::cout << "\n\nTEST 2" << std::endl;
	Span Tab2 ( 4294967295 );
	try
	{
		Tab2.addNumber ( -2147483648 );
		Tab2.addNumber ( 2147483647 );
		std::cout << "The shortest span is : " << Tab2.shortestSpan () << std::endl;
		std::cout << "The longest span is : " << Tab2.longestSpan () << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what () << std::endl;
	}

	std::cout << "\n\nTEST 3" << std::endl;
	Span Tab3 ( 10000 );

	try
	{
		for ( int i = 0; i < 10000; i++ )
		{
			Tab3.addNumber ( i );
		}
		std::cout << "The shortest span is : " << Tab3.shortestSpan () << std::endl;
		std::cout << "The longest span is : " << Tab3.longestSpan () << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what () << std::endl;
	}

	std::cout << "\n\nTEST 4" << std::endl;
	Span Tab4 ( 9999 );

	try
	{
		for ( int i = 0; i < 10001; i++ )
		{
			Tab4.addNumber ( rand () );
		}
		std::cout << "The shortest span is : " << Tab4.shortestSpan () << std::endl;
		std::cout << "The longest span is : " << Tab4.longestSpan () << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what () << std::endl;
	}
	return 0;
}
