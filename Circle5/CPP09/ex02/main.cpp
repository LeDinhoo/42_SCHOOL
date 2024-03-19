/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:15:54 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/13 13:32:25 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>

int main ( int argc, char **argv )
{
	if ( argc == 1 )
	{
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./ex02 <string>" << std::endl;
		return 1;
	}

	// try
	// {
	// 	PmergeMe tab ( argv, argc );
	// 	tab.mergeInsert ();
	// }
	// catch ( std::exception &e )
	// {
	// 	std::cerr << e.what () << std::endl;
	// }
	(void) argv;
	size_t index = 2;
	size_t nb	 = 2;
	size_t temp = index;

	for (size_t i = 0; i < 100; i++)
	{
		if (temp == 0)
		{
			nb++;
			index = pow(2, nb) - index;
			temp = index;
		}
		else
			temp--;
	// INSERT DS VECTOR TRIER LES NON TRIER AVEC INDEX
		std::cout << index << std::endl;
	}

		return 0;
}