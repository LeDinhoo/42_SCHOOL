/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:29:56 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/11 14:39:57 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span ( unsigned int maxSize ) : _maxSixe ( maxSize )
{
	this->_nbTab.reserve ( _maxSixe );
	std::cout << "Span created with maxSize = " << this->_nbTab.capacity () << std::endl;
}

Span::~Span ()
{
}

Span::Span ( const Span &src )
{
	*this = src;
}

Span &Span::operator= ( const Span &rhs )
{
	if ( this != &rhs )
	{
		this->_nbTab   = rhs._nbTab;
		this->_maxSixe = rhs._maxSixe;
	}
	return ( *this );
}
void Span::addNumber ( int number )
{
	if ( _nbTab.size () > _maxSixe )
		throw MaxNumberOfElementsReached ();
	this->_nbTab.push_back ( number );
}

unsigned int Span::longestSpan ()
{
	if ( this->_nbTab.empty () )
		throw EmptyContainer ();
	if ( this->_nbTab.size () == 1 )
		throw OnlyOneElement ();

	int min = this->_nbTab.front ();
	int max = this->_nbTab.front ();
	unsigned int span;

	for ( std::vector<int>::iterator it = this->_nbTab.begin (); it < this->_nbTab.end (); ++it )
	{
		if ( *it < min )
			min = *it;
		if ( *it > max )
			max = *it;
	}
	span = max - min;
	return ( span );
}

unsigned int Span::shortestSpan ()
{
	if ( this->_nbTab.empty () )
		throw EmptyContainer ();
	if ( this->_nbTab.size () == 1 )
		throw OnlyOneElement ();

	std::vector<int> tmp = this->_nbTab;
	std::sort ( tmp.begin (), tmp.end () );
	unsigned int span = tmp[1] - tmp[0];
	for ( std::vector<int>::iterator it = tmp.begin (); it < tmp.end (); ++it )
	{
		if ( ( it + 1 ) != tmp.end () )
		{
			if ( ( *( it + 1 ) - *it ) < (int)span )
				span = *( it + 1 ) - *it;
		}
	}
	return ( span );
}