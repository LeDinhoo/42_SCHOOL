/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:15:43 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 12:00:08 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main ()
{
	const Animal *j = new Dog ();
	const Animal *i = new Cat ();
	delete j; // should not create a leak
	delete i;
	return 0;
}