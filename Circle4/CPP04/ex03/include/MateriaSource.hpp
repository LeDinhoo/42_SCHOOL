/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:51:38 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 15:55:58 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

  public:
	MateriaSource ();
	MateriaSource ( MateriaSource const &src );
	~MateriaSource ();

	MateriaSource &operator= ( MateriaSource const &rhs );

	void learnMateria ( AMateria * );
	AMateria *createMateria ( std::string const &type );

  private:
	AMateria *_materia[4];
};

#endif // MATERIASOURCE_HPP