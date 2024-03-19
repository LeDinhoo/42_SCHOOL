/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:46:22 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 09:49:17 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void swap ( T &a, T &b )
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min ( T const &a, T const &b )
{
	return ( a < b ? a : b );
}

template <typename T> T max ( T const &a, T const &b )
{
	return ( a > b ? a : b );
}

#endif