/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:09:36 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 09:43:12 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate ( void )
{
	srand ( time ( NULL ) );
	int rand = std::rand ();
	if ( rand % 3 == 0 )
	{
		return ( new A );
	}
	else if ( rand % 3 == 1 )
	{
		return ( new B );
	}
	else
	{
		return ( new C );
	}
}

void identify ( Base *p )
{
	if ( dynamic_cast<A *> ( p ) != NULL )
		std::cout << "Pointer : A" << std::endl;
	else if ( dynamic_cast<B *> ( p ) != NULL )
		std::cout << "Pointer : B" << std::endl;
	else if ( dynamic_cast<C *> ( p ) != NULL )
		std::cout << "Pointer : C" << std::endl;
}

void identify ( Base &p )
{
	try
	{
		dynamic_cast<A &> ( p );
		std::cout << "Ref : A" << std::endl;
	}
	catch ( std::exception &e )
	{
	}
	try
	{
		dynamic_cast<B &> ( p );
		std::cout << "Ref : B" << std::endl;
	}
	catch ( std::exception &e )
	{
	}
	try
	{
		dynamic_cast<C &> ( p );
		std::cout << "Ref : C" << std::endl;
	}
	catch ( std::exception &e )
	{
	}
}

int main ()
{
	Base *ptr;
	for ( int i = 0; i < 10; i++ )
	{
		ptr = generate ();
		sleep ( 1 );
		identify ( ptr );
		identify ( *ptr );
		delete ptr;
	}
	return ( 0 );
}