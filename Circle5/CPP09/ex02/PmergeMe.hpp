/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:53:17 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/13 15:01:15 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class PmergeMe
{
  private:
	char **_argv;
	int _argc;
	std::vector< std::pair< int, int > > _vData;
	void parsing ();
	void checkArg ();
	void printBaseList ();
	void fillVector ();
	void printVector ();
	void fillLeftPairs ();

  public:
	PmergeMe ( char **argv, int argc );
	PmergeMe ( const PmergeMe &src );
	~PmergeMe ();

	PmergeMe &operator= ( const PmergeMe &rhs );

	void mergeInsert ();

	class WrongArgumentsError : public std::exception
	{
	  public:
		virtual const char *what () const throw ()
		{
			return ( "Error: Wrong syntax in arguments" );
		}
	};

	class OutOfLimits : public std::exception
	{
	  public:
		virtual const char *what () const throw ()
		{
			return ( "Error: Arguments are out of limit" );
		}
	};
};

#endif