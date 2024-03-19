/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:48:09 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 09:01:53 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serialization.hpp"

int main ()
{
	Data *ptr = new Data;
	ptr->s1 = "Hello";
	ptr->value = 42;
	
	uintptr_t raw = Serialization::serialize ( ptr );
	std::cout << "Serialized: " << raw << std::endl;

	Data *ret = Serialization::deserialize ( raw );
	std::cout << "Deserialized: " << ret->s1 << " " << ret->value << std::endl;

	delete ptr;
	return ( 0 );
}