/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:37:51 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/16 11:36:05 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat () : Animal ( "Cat" ) {
    std::cout << "Cat <default> constructor called" << std::endl;
}

Cat::Cat ( const Cat &src ) : Animal ( src ) {
    *this = src;
    std::cout << "Cat <copy> constructor called" << std::endl;
}

Cat::~Cat () { std::cout << "Cat destructor called" << std::endl; }

Cat &Cat::operator= ( Cat const &rhs ) {
    if ( this != &rhs ) {
	this->type = rhs.getType ();
    }
    return *this;
}