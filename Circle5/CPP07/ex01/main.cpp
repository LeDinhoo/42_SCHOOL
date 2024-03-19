/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:57:51 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 10:27:41 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T> void print ( T &element )
{
	std::cout << element << std::endl;
}

int main ()
{
	std::string test1[] = { "V", "Night", "City" };
	int test2[]			= { 1, 2, 3, 4, 5 };
	float test3[]		= { 1.1, 2.2, 3.3, 4.4, 5.5 };

	std::cout << "Test 1: " << std::endl;
	iter ( test1, 3, print );
	std::cout << std::endl;

	std::cout << "Test 2: " << std::endl;
	iter ( test2, 5, print );
	std::cout << std::endl;

	std::cout << "Test 3: " << std::endl;
	iter ( test3, 5, print );
	std::cout << std::endl;
}