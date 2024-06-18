/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbacquet <cbacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:57 by cbacquet          #+#    #+#             */
/*   Updated: 2024/03/19 17:34:20 by cbacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error : 2 arguments minimum needed" << std::endl;
		return (1);
	}
	for (int i = 1 ; i < argc; i++)
	{
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.size(); j++)
		{
			
			if (!isdigit(arg[j]))
			{
				std::cerr << "Error: the sequence should only take positive integer" << std::endl;
				return (1);
			}
		}
	}
	PmergeMe 	SeqtoSort(argc, argv);
	return (0);
}