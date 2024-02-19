/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:35:42 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 16:28:23 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria ()
{
	std::cout << "AMateria <default> constructor called" << std::endl;
}

AMateria::AMateria ( std::string const &type )
{
	this->type = type;
	std::cout << "AMateria <parameter> constructor called" << std::endl;
}

AMateria::AMateria ( const AMateria &src )
{
	*this = src;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria ()
{
	std::cout << "AMateria destructor called" << std::endl;
	this->type.clear ();
}

AMateria &AMateria::operator= ( const AMateria &rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream &operator<< ( std::ostream &o, const AMateria &i )
{
	o << i.getType ();
	return o;
}

void AMateria::use ( ICharacter &target )
{
	if ( this->type == "ice" )
	{
		std::cout << "* shoots an ice bolt at " << target.getName () << " *" << std::endl;
	}
	else if ( this->type == "cure" )
	{
		std::cout << "* heals " << target.getName () << "'s wounds *" << std::endl;
	}
	else
	{
		std::cout << "Unknown type of materia" << std::endl;
	}
}

std::string const &AMateria::getType () const
{
	return this->type;
}