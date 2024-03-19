/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:09:40 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/11 14:50:25 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

class Span
{
  private:
	std::vector<int> _nbTab;
	unsigned int _maxSixe;

  public:
	Span ( unsigned int maxSize );
	Span ( const Span &src );
	~Span ();

	Span &operator= ( const Span &rhs );

	void addNumber ( int number );
	unsigned int shortestSpan ();
	unsigned int longestSpan ();

	class MaxNumberOfElementsReached : public std::exception
	{
	  public:
		virtual const char *what () const throw ()
		{
			return ( "Error: Max number of elements reached" );
		}
	};

	class EmptyContainer : public std::exception
	{
	  public:
		virtual const char *what () const throw ()
		{
			return ( "Error: Container is empty" );
		}
	};

	class OnlyOneElement : public std::exception
	{
	  public:
		virtual const char *what () const throw ()
		{
			return ( "Error: Only one element in the container" );
		}
	};
};

#endif