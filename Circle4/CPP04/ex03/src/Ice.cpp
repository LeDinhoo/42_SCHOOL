/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:33 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 16:04:55 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Ice::Ice () : AMateria ( "ice" )
{
	std::cout << "Ice <default> constructor called" << std::endl;
}

Ice::Ice ( const Ice &src ) : AMateria ( src )
{
	std::cout << "Ice <copy> constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Ice::~Ice ()
{
	std::cout << "Ice destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Ice &Ice::operator= ( Ice const &rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType ();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AMateria *Ice::clone () const
{
	Ice *newIce = new Ice ();
	return newIce;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */