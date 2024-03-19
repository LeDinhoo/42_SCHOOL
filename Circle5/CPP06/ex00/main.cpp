/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:48:09 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 14:44:01 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return ( 1 );
	}
	ScalarConverter::convert ( argv[1] );

	return ( 0 );
}