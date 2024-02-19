/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:27:08 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/16 11:59:03 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
   public:
    Dog ();
    Dog ( Dog const &src );
    ~Dog ();

    Dog &operator= ( Dog const &rhs );

   private:
    Brain *cell;
};

#endif /* *********************************** DOG_H \*/