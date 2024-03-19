/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 08:49:07 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 09:07:25 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serialization
{
  public:
	static uintptr_t serialize ( Data *ptr );
	static Data *deserialize ( uintptr_t raw );

  private:
	Serialization ();
	~Serialization ();
	Serialization ( const Serialization &rhs );
	Serialization &operator= ( const Serialization &rhs );
};

#endif