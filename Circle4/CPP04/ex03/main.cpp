/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:18:36 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 16:54:14 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// int main ()
// {
// 	AMateria *ice = new Ice ();
// 	AMateria *ice2 = new Ice ();
// 	AMateria *cure = new Cure ();
// 	AMateria *cure2 = new Cure ();

// 	std::cout << "Type of ice: " << ice->getType () << std::endl;

// 	ICharacter *bob = new Character ( "Bob" );

// 	std::cout << "Name of bob: " << bob->getName () << std::endl;

// 	bob->equip ( ice );
// 	bob->equip ( cure );
// 	bob->equip ( ice2 );
// 	bob->equip ( cure2 );

// 	bob->use ( 0, *bob );

// 	bob->unequip ( 0 );

// 	delete ice;

// 	delete bob;
// 	return 0;
// }

int main ()
{
	IMateriaSource *src = new MateriaSource ();
	src->learnMateria ( new Ice () );
	src->learnMateria ( new Cure () );
	ICharacter *me = new Character ( "me" );
	AMateria *tmp;
	tmp = src->createMateria ( "ice" );
	me->equip ( tmp );
	tmp = src->createMateria ( "cure" );
	me->equip ( tmp );
	ICharacter *bob = new Character ( "bob" );
	me->use ( 0, *bob );
	me->use ( 1, *bob );
	delete bob;
	delete me;
	delete src;
	return 0;
}