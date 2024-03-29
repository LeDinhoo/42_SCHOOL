/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:15:43 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 12:18:18 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main ()
{
	AAnimal *tab[10];

	for ( int i = 0; i < 10; i++ )
	{
		if ( i % 2 == 0 )
		{
			tab[i] = new Dog ();
		}
		else
		{
			tab[i] = new Cat ();
		}
	}
	for ( int i = 0; i < 10; i++ )
	{
		tab[i]->makeSound ();
	}
	for ( int i = 0; i < 10; i++ )
	{
		delete tab[i];
	}
	return 0;
}