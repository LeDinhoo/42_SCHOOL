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

PmergeMe::PmergeMe ( char **argv ) : _argv ( argv )
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
		int nb;

		if ( !( iss >> nb ) || !iss.eof () )
		{
			std::cerr << "Error: " << s << " is not a number" << std::endl;
			exit ( 1 );
		}
	}
}

void PmergeMe::parsing ()
{
	checkArg ();
	// std::istringstream iss ( this->_argv[1] );
	// std::string s;
}

void PmergeMe::mergeInsert ()
{
	parsing ();
}