/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:32 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 16:53:50 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character ( std::string const &name ) : _name ( name )
{
	for ( int i = 0; i < 4; i++ )
	{
		this->inventory[i] = NULL;
	}
	std::cout << "Character " << this->_name << "<default> constructor called" << std::endl;
	this->floor = new AMateria *[100];
	for ( int i = 0; i < 100; i++ )
	{
		this->floor[i] = NULL;
	}
}

Character::Character ( const Character &src )
{
	if ( this != &src )
	{
		for ( int i = 0; i < 4; i++ )
		{
			if ( src.inventory[i] != NULL )
			{
				this->inventory[i] = src.inventory[i]->clone ();
			}
			else
			{
				this->inventory[i] = NULL;
			}
		}
	}
	std::cout << "Character " << this->_name << " <copy> constructor called" << std::endl;
}

Character &Character::operator= ( const Character &rhs )
{
	if ( this != &rhs )
	{
		for ( int i = 0; i < 4; i++ )
		{
			if ( rhs.inventory[i] != NULL )
			{
				if ( this->inventory[i] != NULL )
				{
					delete this->inventory[i];
				}
				this->inventory[i] = rhs.inventory[i]->clone ();
			}
			else
			{
				this->inventory[i] = NULL;
			}
		}
	}
	return *this;
}

Character::~Character ()
{
	std::cout << "Character " << this->_name << " destructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
	{
		if ( this->inventory[i] )
		{
			delete this->inventory[i];
		}
	}
	for ( int i = 0; i < 100; i++ )
	{
		if ( this->floor[i] )
		{
			delete this->floor[i];
		}
	}
	delete[] this->floor;
}

std::string const &Character::getName () const
{
	return this->_name;
}

void Character::equip ( AMateria *m )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( this->inventory[i] == NULL )
		{
			this->inventory[i] = m;
			std::cout << "Inventory " << this->inventory[i]->getType () << " equiped" << std::endl;
			break;
		}
	}
}

void Character::unequip ( int idx )
{
	if ( idx >= 0 && idx < 4 )
	{
		if ( this->inventory[idx] != NULL )
		{
			std::cout << "Inventory " << this->inventory[idx]->getType () << " unequiped" << std::endl;
			floor[idx] = this->inventory[idx];
			this->inventory[idx] = NULL;
		}
	}
}

void Character::use ( int idx, ICharacter &target )
{
	if ( idx >= 0 && idx < 4 )
	{
		if ( this->inventory[idx] != NULL )
		{
			this->inventory[idx]->use ( target );
		}
	}
}