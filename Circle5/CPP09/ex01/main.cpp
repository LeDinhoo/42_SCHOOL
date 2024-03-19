/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:15:54 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/12 14:07:56 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main ( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./ex01 <string>" << std::endl;
		return 1;
	}

	RPN rpn ( argv[1] );
	try
	{
		rpn.calculate ();
	}
	catch ( std::exception &e )
	{
		std::cout << e.what () << std::endl;
	}
	return 0;
}