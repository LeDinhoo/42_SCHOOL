/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:37:51 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 12:15:38 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat () : AAnimal ( "Cat" )
{
	this->cell = new Brain ();
	std::cout << "Cat <default> constructor called" << std::endl;
}

Cat::Cat ( const Cat &src ) : AAnimal ( src )
{
	*this = src;
	this->cell = new Brain ( *src.cell );
	std::cout << "Cat <copy> constructor called" << std::endl;
}

Cat::~Cat ()
{
	if ( this->cell != NULL )
		delete this->cell;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator= ( Cat const &rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType ();
		this->cell = new Brain ( *rhs.cell );
		std::cout << "Cat <assignation> operator called" << std::endl;
	}
	return *this;
}

void Cat::makeSound () const
{
	std::cout << "Miaou!" << std::endl;
}