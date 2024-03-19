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
#include <list>
#include <sstream>
#include <string>
#include <vector>

class PmergeMe
{
  private:
	char **_argv;
	std::vector<int> _vData;
	void parsing ();
	void checkArg ();

  public:
	PmergeMe ( char **argv );
	PmergeMe ( const PmergeMe &src );
	~PmergeMe ();

	PmergeMe &operator= ( const PmergeMe &rhs );

	void mergeInsert ();
};

#endif