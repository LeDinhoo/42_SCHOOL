/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:00:23 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/12 12:05:03 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cctype>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define VALUE_ERR "Error: Wrong rate exchange value. It must be a positive number in float or integer format."
#define DATE_ERR "Error: Wrong date format. It must be in the format YYYY-MM-DD | <value>"

class BitcoinExchange
{
  private:
	const std::string _input;
	std::map<std::string, float> _data;
	void fillDatabase ();
	void parsInput ();
	void printPrice ( std::string line );

  public:
	BitcoinExchange ( std::string input );
	BitcoinExchange ( const BitcoinExchange &src );
	~BitcoinExchange ();

	BitcoinExchange &operator= ( const BitcoinExchange &rhs );

	void exchange ();

	class OpenErrorException : public std::exception
	{
	  public:
		virtual const char *what () const throw ()
		{
			return ( "Error: Could not open file." );
		}
	};
};

#endif