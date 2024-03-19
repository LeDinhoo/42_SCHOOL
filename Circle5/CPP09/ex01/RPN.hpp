/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:36:00 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/13 09:36:14 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN
{
  private:
	std::stack<long> _stack;
	std::string _input;

  public:
	RPN ( std::string input );
	RPN ( const RPN &src );
	~RPN ();

	RPN &operator= ( const RPN &rhs );

	void calculate ();

	class MinimalSizeError : public std::exception
	{
	  public:
		virtual const char *what () const throw ()
		{
			return ( "Error: Empty string." );
		}
	};
};

#endif