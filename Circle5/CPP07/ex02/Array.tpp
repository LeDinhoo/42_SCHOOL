/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:44:08 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 11:52:06 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array () : _size ( 0 )
{
	_array = new T;
}

template <typename T> Array<T>::~Array ()
{
	delete[] _array;
}

template <typename T> Array<T>::Array ( unsigned int n ) : _size ( n )
{
	_array = new T[n];
}

template <typename T> Array<T>::Array ( const Array<T> &rhs ) : _size ( rhs._size )
{
	_array = new T[_size];
	for ( unsigned int i = 0; i < _size; i++ )
		_array[i] = rhs._array[i];
}

template <typename T> Array<T> &Array<T>::operator= ( const Array<T> &rhs )
{
	if ( this != &rhs )
	{
		this->_size = rhs._size;
		delete[] _array;
		_array = new T[_size];
		for ( unsigned int i = 0; i < _size; i++ )
			_array[i] = rhs._array[i];
	}
	return ( *this );
}

template <typename T> T &Array<T>::operator[] ( unsigned int i )
{
	if ( i >= this->_size )
		throw OutOfLimitsException ();
	return ( _array[i] );
}

template <typename T> unsigned int Array<T>::size () const
{
	return ( this->_size );
}