/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:49:07 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 09:04:17 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization ()
{
}

Serialization::Serialization ( const Serialization &src )
{
	*this = src;
}

Serialization::~Serialization ()
{
}

Serialization &Serialization::operator= ( const Serialization &rhs )
{
	if ( this != &rhs )
	{
		*this = rhs;
	}
	return ( *this );
}

uintptr_t Serialization::serialize ( Data *ptr )
{
	uintptr_t uintptr = reinterpret_cast<uintptr_t> ( ptr );
	return ( uintptr );
}

Data *Serialization::deserialize ( uintptr_t raw )
{
	Data *dataptr = reinterpret_cast<Data *> ( raw );
	return ( dataptr );
}