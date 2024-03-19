/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:57:51 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 12:03:45 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main ()
{
	// Test with integers
	std::cout << "Integers" << std::endl;
	try
	{
		Array<int> test ( 8 );
		Array<int> test2 ( 24 );

		for ( unsigned int i = 0; i < test.size (); i++ )
			test[i] = i;
		for ( unsigned int i = 0; i < test.size (); i++ )
			std::cout << test[i] << " ";

		std::cout << std::endl;

		for ( unsigned int i = 0; i < test2.size (); i++ )
			test2[i] = i * 2;
		for ( unsigned int i = 0; i < test2.size (); i++ )
			std::cout << test2[i] << " ";
		std::cout << "\nAttempting to access test2[13]" << std::endl;
		test2[13] = 8989867;
		std::cout << test2[13] << std::endl;
		std::cout << "Attempting to access test2[25]" << std::endl;
		test2[25] = 8989867;
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what () << std::endl;
	}

	// Same but with strings
	std::cout << "\nStrings" << std::endl;
	try
	{
		Array<std::string> test ( 8 );
		Array<std::string> test2 ( 24 );

		for ( unsigned int i = 0; i < test.size (); i++ )
			test[i] = "Hello";
		for ( unsigned int i = 0; i < test.size (); i++ )
			std::cout << test[i] << " ";

		std::cout << std::endl;

		for ( unsigned int i = 0; i < test2.size (); i++ )
			test2[i] = "World";
		for ( unsigned int i = 0; i < test2.size (); i++ )
			std::cout << test2[i] << " ";
		std::cout << "\nAttempting to access test2[13]" << std::endl;
		test2[13] = "Hello World";
		std::cout << test2[13] << std::endl;
		std::cout << "Attempting to access test2[25]" << std::endl;
		test2[25] = "Hello World";
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what () << std::endl;
	}

	// Same but with floats
	std::cout << "\nFloats" << std::endl;
	try
	{
		Array<float> test ( 8 );
		Array<float> test2 ( 24 );

		for ( unsigned int i = 0; i < test.size (); i++ )
			test[i] = i * 1.1;
		for ( unsigned int i = 0; i < test.size (); i++ )
			std::cout << test[i] << " ";

		std::cout << std::endl;

		for ( unsigned int i = 0; i < test2.size (); i++ )
			test2[i] = i * 2.2;
		for ( unsigned int i = 0; i < test2.size (); i++ )
			std::cout << test2[i] << " ";
		std::cout << "\nAttempting to access test2[13]" << std::endl;
		test2[13] = 8989867.1;
		std::cout << test2[13] << std::endl;
		std::cout << "Attempting to access test2[25]" << std::endl;
		test2[25] = 8989867.1;
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what () << std::endl;
	}
}