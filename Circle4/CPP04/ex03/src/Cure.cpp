/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:33 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 15:16:21 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cure::Cure () : AMateria ( "cure" )
{
	std::cout << "Cure <default> constructor called" << std::endl;
}

Cure::Cure ( const Cure &src ) : AMateria ( src )
{
	std::cout << "Cure <copy> constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cure::~Cure ()
{
	std::cout << "Cure destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cure &Cure::operator= ( Cure const &rhs )
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

AMateria *Cure::clone () const
{
	Cure *newCure = new Cure ();
	return newCure;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */