/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:44:30 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 14:43:50 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <climits>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>

class ScalarConverter
{
  public:
	ScalarConverter ();
	ScalarConverter ( const ScalarConverter &other );
	~ScalarConverter ();

	ScalarConverter &operator= ( const ScalarConverter &other );

	static void convert ( const std::string &literal );

	class WrongLiteralException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};

	class InfiniteException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};

	class NanException : public std::exception
	{
	  public:
		virtual const char *what () const throw ();
	};

  private:
	static double detectType ( const std::string &literal );
};

#endif
