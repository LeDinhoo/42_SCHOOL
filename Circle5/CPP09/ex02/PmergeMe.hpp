/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:30:07 by cbacquet          #+#    #+#             */
/*   Updated: 2024/03/14 17:21:30 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <climits>
#include <list>
#include <vector>

class PmergeMe
{
	public:

		PmergeMe();
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& src);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& rhv);

		template <typename ContainerType> void printContainer(const ContainerType& container);
		template <typename PairContainerType> bool arePairsSorted(const PairContainerType& pairSequence);
		template <typename PairContainerType> void recursivePairSort(PairContainerType& pairSequence);
		template <typename ContainerType> void mergeInsertionSort(ContainerType& container);
};

#endif