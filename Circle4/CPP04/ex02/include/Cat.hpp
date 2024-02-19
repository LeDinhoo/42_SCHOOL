/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:36:22 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 12:16:37 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
  public:
	Cat ();
	Cat ( Cat const &src );
	~Cat ();

	Cat &operator= ( Cat const &rhs );
	void makeSound () const;

  private:
	Brain *cell;
};

#endif // !CAT_HPP