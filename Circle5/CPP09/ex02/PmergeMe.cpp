/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:43:55 by cbacquet          #+#    #+#             */
/*   Updated: 2024/03/19 17:57:26 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char** argv)
{
	clock_t parseStartTime = clock();
	std::vector<unsigned int> vectorSequence;
	std::deque<unsigned int> dequeSequence;

	for ( int argIndex = 1; argIndex < argc; argIndex++ )
	{
		char* endPtr;
		long int number = strtol(argv[argIndex], &endPtr, 10);
		if ( *endPtr != '\0' || number < 0 || number > UINT_MAX )
		{
			std::cerr << "Error: Invalid number: " << argv[argIndex] << std::endl;
			exit(1);
		}
		if ( std::find(vectorSequence.begin(), vectorSequence.end(), number) != vectorSequence.end() )
		{
			std::cerr << "Error: Duplicate number found " << std::endl;
			exit(1);
		}
		vectorSequence.push_back(static_cast<unsigned int>(number));
		dequeSequence.push_back(static_cast<unsigned int>(number));
	}
	clock_t parseEndTime		 = clock();
	double parseTimeMicroseconds = static_cast<double>(parseEndTime - parseStartTime) / CLOCKS_PER_SEC * 1000000;

	std::cout << "\nBefore: ";
	printContainer(vectorSequence);

	clock_t vectorStartTime = clock();
	mergeInsertionSort(vectorSequence);
	clock_t vectorEndTime = clock();
	double vectorProcessingTimeMicroseconds =
		static_cast<double>(vectorEndTime - vectorStartTime) / CLOCKS_PER_SEC * 1000000 + parseTimeMicroseconds;

	clock_t dequeStartTime = clock();
	mergeInsertionSort(dequeSequence);
	clock_t dequeEndTime = clock();
	double dequeProcessingTimeMicroseconds =
		static_cast<double>(dequeEndTime - dequeStartTime) / CLOCKS_PER_SEC * 1000000 + parseTimeMicroseconds;

	std::cout << "\n";

	std::cout << "After: ";
	printContainer(vectorSequence);

	std::cout << "\n";

	std::cout << "Time to parse a range of " << argc - 1 << " elements: " << parseTimeMicroseconds << " microseconds"
			  << std::endl;
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::vector: " << vectorProcessingTimeMicroseconds << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::deque: " << dequeProcessingTimeMicroseconds << " microseconds" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	(void)rhs;
	return (*this);
}

template <typename ContainerType> void PmergeMe::printContainer(const ContainerType& container)
{
	for ( typename ContainerType::const_iterator it = container.begin(); it != container.end(); ++it )
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename PairContainerType> bool PmergeMe::arePairsSorted(const PairContainerType& pairSequence)
{
	for ( size_t i = 0; i < pairSequence.size() - 1; i++ )
		if ( pairSequence[i] < pairSequence[i + 1] )
			return false;
	return true;
}

template <typename PairContainerType> void PmergeMe::recursivePairSort(PairContainerType& pairSequence)
{
	if ( arePairsSorted(pairSequence) )
		return;

	for ( size_t i = 0; i < pairSequence.size() - 1; i++ )
	{
		if ( pairSequence[i] > pairSequence[i + 1] )
		{
			std::swap(pairSequence[i], pairSequence[i + 1]);
			recursivePairSort(pairSequence);
		}
	}
}

template <typename ContainerType> void PmergeMe::mergeInsertionSort(ContainerType& container)
{
	bool hasOddElement = false;
	unsigned int lastOddElement;
	if ( container.size() % 2 != 0 )
	{
		hasOddElement  = true;
		lastOddElement = container.back();
		container.pop_back();
	}

	std::vector<std::pair<unsigned int, unsigned int> > pairSequence;
	typename ContainerType::iterator it = container.begin();
	while ( std::distance(it, container.end()) >= 2 )
	{
		int leftValue = *it;
		++it;
		int rightValue = *it;
		if ( rightValue > leftValue )
			std::swap(leftValue, rightValue);
		pairSequence.push_back(std::make_pair(leftValue, rightValue));
		++it;
	}

	if ( container.size() >= 700 )
		std::sort(pairSequence.begin(), pairSequence.end());
	else
		recursivePairSort(pairSequence);

	container.clear();

	for ( typename std::vector<std::pair<unsigned int, unsigned int> >::iterator pairIt = pairSequence.begin();
		  pairIt != pairSequence.end(); ++pairIt )
	{
		container.push_back(pairIt->first);
	}

	size_t insertIndex = 2;
	size_t interval	   = 2;
	size_t position	   = insertIndex;
	int counter		   = 0;

	typename ContainerType::iterator insertPosition = container.begin();
	container.insert(insertPosition, pairSequence[0].second);

	for ( size_t i = 1; i < pairSequence.size(); i++ )
	{
		typename ContainerType::iterator it = container.begin();

		if ( counter == 0 )
		{
			insertIndex = pow(2, interval) - insertIndex;
			interval++;
			counter = insertIndex;
		}
		else
			counter--;
		if ( insertIndex > pairSequence.size() )
			insertIndex = pairSequence.size() - 1;
		position = insertIndex;

		while ( position < container.size() && position != 0 )
		{
			if ( pairSequence[i].second <= container[position] && pairSequence[i].second >= container[position - 1] )
			{
				container.insert(it + (position), pairSequence[i].second);
				break;
			}
			else if ( pairSequence[i].second <= container[position - 1] )
				position--;
			else
				position++;
			if ( position == 0 )
			{
				container.insert(it, pairSequence[i].second);
				break;
			}
		}
	}

	if ( hasOddElement )
	{
		insertPosition = container.begin();
		if ( lastOddElement > container[0] )
		{
			for ( size_t i = 1; i < container.size(); i++ )
			{
				if ( lastOddElement < container[i] && lastOddElement > container[i - 1] )
				{
					container.insert(insertPosition + i, lastOddElement);
					break;
				}
				if ( i == container.size() - 1 )
				{
					container.push_back(lastOddElement);
					break;
				}
			}
		}
		else
		{
			container.insert(insertPosition, lastOddElement);
		}
	}
}
