/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:32:32 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 16:52:10 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter
{
  private:
	std::string const _name;
	AMateria *inventory[4];
	AMateria **floor = NULL;

  public:
	Character ( std::string const &name );
	Character ( const Character &src );
	Character &operator= ( const Character &rhs );

	~Character ();
	std::string const &getName () const;
	void equip ( AMateria *m );
	void unequip ( int idx );
	void use ( int idx, ICharacter &target );
};

#endif // !ICHARACTER_HPP