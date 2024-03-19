/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:51:20 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 10:27:45 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T1, typename T2> void iter ( T1 *array, T2 size, void ( *function ) ( T1 & ) )
{
	for ( T2 i = 0; i < size; i++ )
	{
		function ( array[i] );
	}
}

#endif
