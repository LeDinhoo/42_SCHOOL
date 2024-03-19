/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:46:09 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 08:27:19 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter ()
{
}

ScalarConverter::ScalarConverter ( const ScalarConverter &src )
{
	(void)src;
}

ScalarConverter::~ScalarConverter ()
{
}

ScalarConverter &ScalarConverter::operator= ( const ScalarConverter &rhs )
{
	(void)rhs;
	return ( *this );
}

const char *ScalarConverter::WrongLiteralException::what () const throw ()
{
	return ( "Error: Wrong literal" );
}

const char *ScalarConverter::InfiniteException::what () const throw ()
{
	return ( "Error: Infinite" );
}

const char *ScalarConverter::NanException::what () const throw ()
{
	return ( "Error: Nan" );
}

int countSign ( const std::string &literal, char toFind )
{
	int count = 0;

	for ( std::size_t i = 0; i < literal.length (); ++i )
	{
		if ( literal[i] == toFind )
			++count;
	}

	return count;
}

int notValidString ( const std::string &literal )
{
	if ( literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff" || literal == "+inf" ||
		 literal == "+inff" || literal == "-inf" || literal == "-inff" )
		return ( 0 );
	if ( countSign ( literal, '.' ) > 1 || countSign ( literal, 'f' ) > 1 || countSign ( literal, '-' ) > 1 ||
		 countSign ( literal, '+' ) > 1 )
		return ( 1 );
	for ( std::size_t i = 0; i < literal.length (); ++i )
	{
		if ( !isdigit ( literal[i] ) && literal[i] != '.' && literal[i] != 'f' && literal[i] != '-' &&
			 literal[i] != '+' )
			return ( 1 );
	}
	return ( 0 );
}

void printInf ( double d )
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << d << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void printNan ()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

double ScalarConverter::detectType ( const std::string &literal )
{
	int len = literal.length ();

	if ( len == 1 && !isdigit ( literal[0] ) )
		return ( static_cast<double> ( literal[0] ) );

	if ( notValidString ( literal ) )
		throw ScalarConverter::WrongLiteralException ();

	double d = std::atof ( literal.c_str () );
	if ( isinf ( d ) )
	{
		printInf ( d );
		throw ScalarConverter::InfiniteException ();
	}
	if ( isnan ( d ) )
	{
		printNan ();
		throw ScalarConverter::NanException ();
	}
	return ( d );
}

void ScalarConverter::convert ( const std::string &literal )
{
	try
	{
		double value = ScalarConverter::detectType ( literal );
		if ( value < CHAR_MAX && value >= 32 )
			std::cout << "char: '" << static_cast<char> ( value ) << "'" << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
		if ( value < INT_MAX && value > INT_MIN )
			std::cout << "int: " << static_cast<int> ( value ) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float> ( value ) << "f" << std::endl;
		std::cout << "double: " << static_cast<double> ( value ) << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what () << std::endl;
	}
}
