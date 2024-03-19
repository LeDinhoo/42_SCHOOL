/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:02:55 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/13 13:01:35 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN ( std::string input ) : _input ( input )
{
}

RPN::RPN ( const RPN &src )
{
	*this = src;
}

RPN::~RPN ()
{
}

RPN &RPN::operator= ( const RPN &rhs )
{
	if ( this != &rhs )
	{
		this->_stack = rhs._stack;
		this->_input = rhs._input;
	}
	return ( *this );
}

void RPN::calculate ()
{
	std::string str = this->_input;

	if ( str.empty () )
		throw MinimalSizeError ();

	for ( std::string::iterator it = str.begin (); it != str.end (); ++it )
	{
		if ( *it == ' ' && *( it + 1 ) == ' ' )
			throw std::runtime_error ( "Error: Invalid character." );
	}

	std::istringstream iss ( str );
	std::string token;
	while ( std::getline ( iss, token, ' ' ) )
	{
		if ( token == "+" )
		{
			if ( this->_stack.size () < 2 )
				throw std::runtime_error ( "Error: Not enough values." );
			long a = this->_stack.top ();
			this->_stack.pop ();
			long b = this->_stack.top ();
			this->_stack.pop ();
			this->_stack.push ( a + b );
		}
		else if ( token == "-" )
		{
			if ( this->_stack.size () < 2 )
				throw std::runtime_error ( "Error: Not enough values." );
			long a = this->_stack.top ();
			this->_stack.pop ();
			long b = this->_stack.top ();
			this->_stack.pop ();
			this->_stack.push ( b - a );
		}
		else if ( token == "*" )
		{
			if ( this->_stack.size () < 2 )
				throw std::runtime_error ( "Error: Not enough values." );
			long a = this->_stack.top ();
			this->_stack.pop ();
			long b = this->_stack.top ();
			this->_stack.pop ();
			this->_stack.push ( a * b );
		}
		else if ( token == "/" )
		{
			if ( this->_stack.size () < 2 )
				throw std::runtime_error ( "Error: Not enough values." );
			long a = this->_stack.top ();
			this->_stack.pop ();
			long b = this->_stack.top ();
			this->_stack.pop ();
			if ( a == 0 )
				throw std::runtime_error ( "Error: Division by zero." );
			this->_stack.push ( b / a );
		}
		else
		{
			for ( std::string::iterator it = token.begin (); it != token.end (); ++it )
			{
				if ( !isdigit ( *it ) )
					throw std::runtime_error ( "Error: Invalid character." );
			}
			long value;
			value = std::atoi ( token.c_str () );
			this->_stack.push ( value );
		}
	}
	if ( this->_stack.size () != 1 )
		throw std::runtime_error ( "Error: Too many values remaining." );
	std::cout << this->_stack.top () << std::endl;
}