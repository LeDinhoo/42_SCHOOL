/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:14 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 13:56:23 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria
{

  public:
	Ice ();
	Ice ( Ice const &src );
	~Ice ();

	Ice &operator= ( Ice const &rhs );
	AMateria *clone () const;

  private:
};

#endif /* ************************************************************* ICE_H */