/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:54:56 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/11 12:43:28 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class NotFoundException : public std::exception
{
  public:
	const char *what () const throw ()
	{
		return ( " Number not found" );
	}
};

template <typename T> typename T::const_iterator easyfind ( const T &haystack, int needle )
{
	typename T::const_iterator it = std::find ( haystack.begin (), haystack.end (), needle );

	if ( it != haystack.end () )
		return it;

	throw NotFoundException ();
}

#endif