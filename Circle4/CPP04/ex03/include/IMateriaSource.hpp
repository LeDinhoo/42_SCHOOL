/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:51:25 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 15:51:26 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{

  public:
	virtual ~IMateriaSource ()
	{
	}
	virtual void learnMateria ( AMateria * ) = 0;
	virtual AMateria *createMateria ( std::string const &type ) = 0;
};

#endif // IMATERIASOURCE_HPP