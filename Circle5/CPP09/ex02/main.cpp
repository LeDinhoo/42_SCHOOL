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

int main ( int argc, char **argv )
{
	if ( argc == 1 )
	{
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./ex02 <string>" << std::endl;
		return 1;
	}

	PmergeMe tab ( argv );
	tab.mergeInsert ();

	return 0;
}