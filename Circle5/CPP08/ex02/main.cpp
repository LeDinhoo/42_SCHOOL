/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:15:54 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/11 15:18:43 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main ()
{
	MutantStack<int> mstack;
	mstack.push ( 5 );
	mstack.push ( 17 );
	std::cout << "Top of the stack : " << mstack.top () << std::endl;
	mstack.pop ();
	std::cout << "Size of the stack : " << mstack.size () << std::endl;
	mstack.push ( 3 );
	mstack.push ( 5 );
	mstack.push ( 737 );
	mstack.push ( 0 );
	MutantStack<int>::iterator it  = mstack.begin ();
	MutantStack<int>::iterator ite = mstack.end ();
	++it;
	--it;
	while ( it != ite )
	{
		std::cout << "Value of the stack : " << *it << std::endl;
		++it;
	}
	std::stack<int> s ( mstack );
	return 0;
}