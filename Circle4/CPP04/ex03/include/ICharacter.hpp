/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:32 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 16:45:14 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <iostream>
#include <string>

class AMateria;

class ICharacter
{
  public:
	virtual ~ICharacter ()
	{
	}
	virtual std::string const &getName () const = 0;
	virtual void equip ( AMateria *m ) = 0;
	virtual void unequip ( int idx ) = 0;
	virtual void use ( int idx, ICharacter &target ) = 0;
};

#endif // !ICHARACTER_HPP