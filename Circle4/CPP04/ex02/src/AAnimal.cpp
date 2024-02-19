/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:24:09 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 12:17:11 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal ()
{
	std::cout << "AAnimal <default> constructor called" << std::endl;
}

AAnimal::AAnimal ( std::string type )
{
	std::cout << "AAnimal <parameter> constructor called" << std::endl;
	this->type = type;
}

AAnimal::AAnimal ( const AAnimal &src )
{
	*this = src;
	std::cout << "AAnimal <copy> constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal ()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &AAnimal::operator= ( AAnimal const &rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		std::cout << "AAnimal <assignation> operator called" << std::endl;
	}
	return *this;
}

std::ostream &operator<< ( std::ostream &o, AAnimal const &i )
{
	o << "Type: " << i.getType ();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType () const
{
	return this->type;
}

/* ************************************************************************** */