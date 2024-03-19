/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:30:49 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/13 15:03:50 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe ( char **argv, int argc ) : _argv ( argv ), _argc ( argc )
{
}

PmergeMe::~PmergeMe ()
{
}

PmergeMe::PmergeMe ( const PmergeMe &src )
{
	*this = src;
}

PmergeMe &PmergeMe::operator= ( const PmergeMe &rhs )
{
	if ( this != &rhs )
	{
		// *this = rhs;
	}
	return *this;
}

void PmergeMe::checkArg ()
{
	for ( int i = 1; this->_argv[i]; i++ )
	{
		std::istringstream iss ( this->_argv[i] );
		std::string s = this->_argv[i];
		int nb		  = atoi ( s.c_str () );

		if ( nb > std::numeric_limits< int >::max () || nb < 0 )
			throw OutOfLimits ();
		if ( !( iss >> nb ) || !iss.eof () )
			throw WrongArgumentsError ();
	}
}

void PmergeMe::printBaseList ()
{
	std::cout << "Before: ";
	for ( int i = 1; this->_argv[i]; i++ )
	{
		std::string s = this->_argv[i];
		std::cout << s << " ";
	}
}

void swapPairs ( std::pair< int, int > &a, std::pair< int, int > &b )
{
	std::pair< int, int > temp = a;
	a						   = b;
	b						   = temp;
}

void recursiveSort ( std::vector< std::pair< int, int > > &vecData, int n )
{
	if ( n <= 1 )
	{
		return;
	}

	for ( int i = 0; i < n - 1; ++i )
	{
		if ( vecData[i].first > vecData[i + 1].first )
		{
			swapPairs ( vecData[i], vecData[i + 1] );
		}
	}

	recursiveSort ( vecData, n - 1 );
}

void vecSort ( std::vector< std::pair< int, int > > &vecData )
{
	recursiveSort ( vecData, vecData.size () );
}

void PmergeMe::fillVector ()
{
	for ( int i = 2; i < this->_argc - 2; i += 2 )
	{
		int nb1 = atoi ( this->_argv[i] );
		int nb2 = atoi ( this->_argv[i + 1] );
		if ( nb1 < nb2 )
			this->_vData.push_back ( std::make_pair ( nb2, nb1 ) );
		else
			this->_vData.push_back ( std::make_pair ( nb1, nb2 ) );
	}
}

void PmergeMe::printVector ()
{
	for ( std::vector< std::pair< int, int > >::iterator it = this->_vData.begin (); it < this->_vData.end (); ++it )
	{
		std::cout << it->first << " : " << it->second << "\n";
	}
}

void PmergeMe::fillLeftPairs ()
{
	for ( std::vector< std::pair< int, int > >::iterator it = this->_vData.begin (); it < this->_vData.end (); ++it )
	{
		std::cout << it->first << " : " << it->second << "\n";
	}
}

void PmergeMe::parsing ()
{
	checkArg ();
	// printBaseList ();
}

void PmergeMe::mergeInsert ()
{
	parsing ();
	fillVector ();
	vecSort ( this->_vData );
	printVector ();
	fillLeftPairs ();
}

