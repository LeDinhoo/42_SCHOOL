/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:28:55 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 11:55:03 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
  public:
	Array ();
	Array ( unsigned int size );
	Array<T> ( Array<T> const &src );
	~Array ();

	Array<T> &operator= ( Array<T> const &rhs );
	T &operator[] ( unsigned int i );

	unsigned int size () const;

	class OutOfLimitsException : public std::exception
	{
	  public:
		virtual const char *what () const throw ()
		{
			return ( "Error: Index out of limits" );
		}
	};

  private:
	T *_array;
	unsigned int _size;
};

#include "Array.tpp"

#endif