/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:16:10 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/11 15:18:24 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin ()
	{
		return std::stack<T>::c.begin ();
	}

	iterator end ()
	{
		return std::stack<T>::c.end ();
	}
};

#endif