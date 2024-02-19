/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:54:14 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 16:04:58 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource ()
{
	for ( int i = 0; i < 4; i++ )
	{
		this->_materia[i] = NULL;
	}
	std::cout << "MateriaSource <default> constructor called" << std::endl;
}

MateriaSource::MateriaSource ( const MateriaSource &src )
{
	if ( this != &src )
	{
		for ( int i = 0; i < 4; i++ )
		{
			if ( src._materia[i] != NULL )
			{
				this->_materia[i] = src._materia[i]->clone ();
			}
			else
			{
				this->_materia[i] = NULL;
			}
		}
	}
	std::cout << "MateriaSource <copy> constructor called" << std::endl;
}

MateriaSource::~MateriaSource ()
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( this->_materia[i] != NULL )
		{
			delete this->_materia[i];
		}
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &MateriaSource::operator= ( const MateriaSource &rhs )
{
	if ( this != &rhs )
	{
		for ( int i = 0; i < 4; i++ )
		{
			if ( rhs._materia[i] != NULL )
			{
				if ( this->_materia[i] != NULL )
				{
					delete this->_materia[i];
				}
				this->_materia[i] = rhs._materia[i]->clone ();
			}
			else
			{
				this->_materia[i] = NULL;
			}
		}
	}
	return ( *this );
}

void MateriaSource::learnMateria ( AMateria *m )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( this->_materia[i] == NULL )
		{
			this->_materia[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria ( std::string const &type )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( this->_materia[i] != NULL && this->_materia[i]->getType () == type )
		{
			return this->_materia[i]->clone ();
		}
	}
	return NULL;
}
