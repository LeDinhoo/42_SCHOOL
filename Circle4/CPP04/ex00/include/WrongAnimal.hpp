/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:00:34 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/16 11:39:08 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iomanip>
#include <iostream>
#include <string>

class WrongAnimal {
   public:
    WrongAnimal ();
    WrongAnimal ( std::string _type );
    WrongAnimal ( const WrongAnimal &src );
    ~WrongAnimal ();

    WrongAnimal &operator= ( const WrongAnimal &rhs );
    std::string getType () const;
    void makeSound () const;

   protected:
    std::string _type;
};

std::ostream &operator<< ( std::ostream &o, WrongAnimal const &i );

#endif