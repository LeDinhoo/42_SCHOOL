/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:46:41 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/11 12:44:48 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ()
{
	std::vector<int> nbVector;
	for ( int i = 1; i <= 5; i++ )
		nbVector.push_back ( i );

	std::cout << "nbVector contains :";
	for ( std::vector<int>::iterator it = nbVector.begin (); it != nbVector.end (); ++it )
		std::cout << ' ' << *it;

	try
	{
		std::cout << "\nTrying to find 1 : " << *easyfind ( nbVector, 1 );
		std::cout << "\nTrying to find 10 : " << *easyfind ( nbVector, 10 );
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what () << "\n";
	}

	return 0;
}
