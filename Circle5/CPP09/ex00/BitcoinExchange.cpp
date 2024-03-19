/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:40:45 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/12 12:27:57 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange ( std::string input ) : _input ( input )
{
}

BitcoinExchange::BitcoinExchange ( const BitcoinExchange &src )
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange ()
{
}

BitcoinExchange &BitcoinExchange::operator= ( const BitcoinExchange &rhs )
{
	if ( this != &rhs )
	{
		this->_data = rhs._data;
	}
	return ( *this );
}

void BitcoinExchange::fillDatabase ()
{
	std::ifstream dataFile ( "./data.csv" );

	if ( !dataFile.is_open () )
		throw OpenErrorException ();

	// Skip the first line
	std::string firstLine;
	std::getline ( dataFile, firstLine );

	for ( std::string line; std::getline ( dataFile, line ); )
	{
		// Put the date in a string
		std::string date = line.substr ( 0, 10 );

		// Put the value in a float
		std::stringstream ss ( line.substr ( 11, line.length () ) );
		float value;
		ss >> value;

		// Check if the value is a number
		if ( ss.fail () || !ss.eof () )
			throw std::runtime_error ( VALUE_ERR );

		// Put the date and the value in the map
		_data[date] = value;
	}
	dataFile.close ();
}

// Check if the date is in the right format
void checkDate ( std::string line )
{
	// Check the date format
	std::string date;
	date = line.substr ( 0, 11 );
	if ( date.at ( 4 ) != '-' || date.at ( 7 ) != '-' || date.at ( 10 ) != ' ' )
		throw std::runtime_error ( "Error: Wrong date format. It must be in the format YYYY-MM-DD | <value>" );

	// Check de value of date
	for ( int i = 0; i < 10; i++ )
	{
		if ( i == 4 || i == 7 )
			continue;
		if ( !isdigit ( date.at ( i ) ) )
			throw std::runtime_error ( "Error: Date must contain only numbers." );
	}

	// Check the year value
	if ( std::atoi ( date.substr ( 0, 4 ).c_str () ) < 2009 || std::atoi ( date.substr ( 0, 4 ).c_str () ) > 2022 )
		throw std::runtime_error ( "Error: Wrong year value. It must be between 2009 and 2022." );

	// Check the month value
	if ( std::atoi ( date.substr ( 5, 2 ).c_str () ) < 1 || std::atoi ( date.substr ( 5, 2 ).c_str () ) > 12 )
		throw std::runtime_error ( "Error: Wrong month value. It must be between 1 and 12." );

	// Check the day value
	if ( std::atoi ( date.substr ( 8, 2 ).c_str () ) < 1 || std::atoi ( date.substr ( 8, 2 ).c_str () ) > 31 )
		throw std::runtime_error ( "Error: Wrong day value. It must be between 1 and 31." );

	// Check for February
	if ( std::atoi ( date.substr ( 5, 2 ).c_str () ) == 2 )
	{
		if ( std::atoi ( date.substr ( 8, 2 ).c_str () ) > 29 )
			throw std::runtime_error ( "Error: Wrong day value. It must be between 1 and 29." );
	}
}

void checkValue ( std::string line )
{
	std::string value;

	// Check the value format
	value = line.substr ( 11, line.length () );
	if ( value.at ( 0 ) != '|' || value.at ( 1 ) != ' ' )
		throw std::runtime_error ( "Error: Wrong value format. It must be in the format YYYY-MM-DD | <value>" );

	// Check if it has a negative sign
	if ( value.at ( 2 ) == '-' )
		throw std::runtime_error ( VALUE_ERR );

	// Check if it is a float or a integer
	std::stringstream ss ( value.substr ( 2, value.length () ) );
	float val;
	ss >> val;
	if ( ss.fail () || !ss.eof () )
		throw std::runtime_error ( VALUE_ERR );

	// Check if it's beetween 0 and 1000
	if ( val < 0 || val > 1000 )
		throw std::runtime_error (
			"Error: Wrong rate exchange value. It must be beetwen 0 and 1000 in float or integer format." );
}

void checkLine ( std::string line )
{
	// Check the minimum length of the line
	if ( line.length () < 14 )
		throw std::runtime_error ( "Error: Minimum length of the line is 14 characters." );

	// Check the date and the value
	checkDate ( line );
	checkValue ( line );
}

void BitcoinExchange::printPrice ( std::string line )
{
	std::string date;
	float value;
	std::stringstream ss;

	// Put the date in a string
	date = line.substr ( 0, 10 );

	// Put the value in a float
	ss << line.substr ( 12, line.length () );
	ss >> value;

	// Print the price of the bitcoin
	if ( this->_data.find ( date ) == this->_data.end () )
	{
		std::map<std::string, float>::iterator it = this->_data.lower_bound ( date );
		std::cout << date << " => " << value << " = " << std::fixed << std::setprecision ( 2 ) << value * it->second
				  << std::endl;
	}
	else
		std::cout << date << " => " << value << " = " << std::fixed << std::setprecision ( 2 )
				  << value * this->_data[date] << std::endl;
}

void BitcoinExchange::parsInput ()
{
	std::string line;

	std::ifstream inputData ( this->_input.c_str () );
	if ( !inputData.is_open () )
	{
		throw OpenErrorException ();
	}

	try
	{
		for ( std::string line; std::getline ( inputData, line ); )
		{
			try
			{
				checkLine ( line );
				printPrice ( line );
			}
			catch ( const std::exception &e )
			{
				std::cerr << line << ": " << e.what () << std::endl;
			}
		}
	}
	catch ( const std::exception &e )
	{
		std::cerr << "Exception while processing input data file: " << e.what () << std::endl;
	}
}

void BitcoinExchange::exchange ()
{
	fillDatabase ();
	parsInput ();
}