/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:15:54 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/12 11:52:53 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main ( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./ex00 <filename>" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange be ( argv[1] );
		be.exchange ();
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}

	return 0;
}