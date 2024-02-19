/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:23:07 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 16:28:32 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
  protected:
	std::string type;

  public:
	AMateria ();
	AMateria ( std::string const &type );
	AMateria ( const AMateria &src );
	virtual ~AMateria ();

	AMateria &operator= ( const AMateria &rhs );

	std::string const &getType () const; // Returns the materia type
	virtual AMateria *clone () const = 0;
	virtual void use ( ICharacter &target );
};

std::ostream &operator<< ( std::ostream &o, const AMateria &i );

#endif // !AMATERIA_HPP