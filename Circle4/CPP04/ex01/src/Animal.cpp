/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:24:09 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 11:30:07 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal ()
{
	std::cout << "Animal <default> constructor called" << std::endl;
}

Animal::Animal ( std::string type )
{
	std::cout << "Animal <parameter> constructor called" << std::endl;
	this->type = type;
}

Animal::Animal ( const Animal &src )
{
	*this = src;
	std::cout << "Animal <copy> constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal ()
{
	std::cout << "Animal destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &Animal::operator= ( Animal const &rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		std::cout << "Animal <assignation> operator called" << std::endl;
	}
	return *this;
}

std::ostream &operator<< ( std::ostream &o, Animal const &i )
{
	o << "Type: " << i.getType ();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Animal::makeSound () const
{
	if ( this->type == "Dog" )
		std::cout << "Wouf Wouf!" << std::endl;
	else if ( this->type == "Cat" )
		std::cout << "Miaou Miaou!" << std::endl;
	else
		std::cout << "I don't know what sound I make!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType () const
{
	return this->type;
}

/* ************************************************************************** */