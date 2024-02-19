/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:31:47 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 12:15:49 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog () : AAnimal ( "Dog" )
{
	this->cell = new Brain ();
	std::cout << "Dog <default> constructor called" << std::endl;
}

Dog::Dog ( const Dog &src ) : AAnimal ( src )
{
	*this = src;
	this->cell = new Brain ( *src.cell );
	std::cout << "Dog <copy> constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog ()
{
	if ( this->cell != NULL )
		delete this->cell;
	std::cout << "Dog destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &Dog::operator= ( Dog const &rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType ();
		this->cell = new Brain ( *rhs.cell );
		std::cout << "Dog <assignation> operator called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound () const
{
	std::cout << "Ouaf!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */