/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:37:51 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/15 11:22:51 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat () : WrongAnimal ( "WrongCat" ) {
    std::cout << "WrongCat <default> constructor called" << std::endl;
}

WrongCat::WrongCat ( const WrongCat &src ) : WrongAnimal ( src ) {
    *this = src;
    std::cout << "WrongCat <copy> constructor called" << std::endl;
}

WrongCat::~WrongCat () {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator= ( WrongCat const &rhs ) {
    if ( this != &rhs ) {
	this->_type = rhs.getType ();
    }
    return *this;
}