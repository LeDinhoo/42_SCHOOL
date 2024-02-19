/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:15:43 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/16 11:39:19 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main () {
    // Affichage de séparateurs pour délimiter les sections du programme
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;

    // Création d'un objet Animal
    Animal a;

    // Affichage de saut de ligne pour séparation
    std::cout << std::endl;
    std::cout << std::endl;

    // Création d'un objet Animal en utilisant le constructeur de copie
    Animal b ( a );

    // Affichage de saut de ligne pour séparation
    std::cout << std::endl;
    std::cout << std::endl;

    // Création d'un objet Animal en utilisant le constructeur avec chaîne de
    // caractères
    Animal c ( "Animal" );

    // Affichage de saut de ligne pour séparation
    std::cout << std::endl;
    std::cout << std::endl;

    // Création d'objets Dog
    Dog d;

    // Affichage de saut de ligne pour séparation
    std::cout << std::endl;
    std::cout << std::endl;

    // Création d'objets Cat
    Cat e;

    // Affichage de saut de ligne pour séparation
    std::cout << std::endl;
    std::cout << std::endl;

    // Création d'objets WrongAnimal et WrongCat en utilisant new
    const WrongAnimal *f = new WrongAnimal;

    // Affichage de saut de ligne pour séparation
    std::cout << std::endl;
    std::cout << std::endl;

    const WrongCat *g = new WrongCat;

    // Affichage de saut de ligne pour séparation
    std::cout << std::endl;
    std::cout << std::endl;

    // Affichage de séparateurs pour délimiter les sections du programme
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;

    // Affichage des objets en utilisant l'opérateur <<
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << *f << std::endl;
    std::cout << *g << std::endl;

    // Affichage de séparateurs pour délimiter les sections du programme
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;

    // Appel de la méthode makeSound() pour chaque objet
    a.makeSound ();
    b.makeSound ();
    c.makeSound ();
    d.makeSound ();
    e.makeSound ();
    f->makeSound ();
    g->makeSound ();

    // Affichage de séparateurs pour délimiter les sections du programme
    std::cout << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << std::endl;

    // Libération de la mémoire allouée avec new
    delete f;
    delete g;

    return 0;
}