/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:09:19 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/16 11:36:35 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal () {
    std::cout << "WrongAnimal <default> constructor called" << std::endl;
}

WrongAnimal::WrongAnimal ( std::string _type ) {
    this->_type = _type;
    std::cout << "WrongAnimal <parameter> constructor called" << std::endl;
}

WrongAnimal::WrongAnimal ( WrongAnimal const &src ) {
    *this = src;
    std::cout << "WrongAnimal <copy> constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal () {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator= ( const WrongAnimal &rhs ) {
    this->_type = rhs._type;
    return *this;
}

std::string WrongAnimal::getType () const { return this->_type; }

void WrongAnimal::makeSound () const {
    if ( this->_type == "WrongCat" )
	std::cout << "KEWKEWKEWKEWKEW!" << std::endl;
    else
	std::cout << "I.. don't know..." << std::endl;
}

std::ostream &operator<< ( std::ostream &o, WrongAnimal const &i ) {
    o << "Type: " << i.getType ();
    return o;
}