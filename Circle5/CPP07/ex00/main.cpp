/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:45:56 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 09:47:58 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main ( void )
{
	int a = 2;
	int b = 3;
	::swap ( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min ( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max ( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap ( c, d );
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min ( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max ( c, d ) << std::endl;
	return 0;
}