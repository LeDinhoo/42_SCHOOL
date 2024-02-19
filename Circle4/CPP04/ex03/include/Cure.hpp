/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:14 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 13:56:23 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{

  public:
	Cure ();
	Cure ( Cure const &src );
	~Cure ();

	Cure &operator= ( Cure const &rhs );
	AMateria *clone () const;

  private:
};

#endif /* ************************************************************* Cure_H */