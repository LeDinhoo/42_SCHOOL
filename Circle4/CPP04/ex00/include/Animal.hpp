/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:48:50 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/16 11:40:38 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Directives de préprocesseur pour éviter les inclusions multiples
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

// Inclusions de bibliothèques nécessaires
#include <iomanip>
#include <iostream>
#include <string>

// Déclaration de la classe Animal
class Animal {
   public:
    // Constructeurs et destructeur
    Animal ();			   // Constructeur par défaut
    Animal ( std::string type );   // Constructeur avec un int
    Animal ( Animal const &src );  // Constructeur de copie
    ~Animal ();			   // Destructeur

    // Surcharge de l'opérateur d'assignation
    Animal &operator= ( Animal const &rhs );

    // Méthodes publiques
    std::string getType () const;  // Méthode pour obtenir le type
    void makeSound () const;	   // Méthode pour émettre un son

   protected:
    // Attribut protégé représentant le type de l'animal
    std::string type;
};

// Surcharge de l'opérateur de sortie pour afficher un Animal
std::ostream &operator<< ( std::ostream &o, Animal const &i );

// Fin de la directive de préprocesseur
#endif /* ******************/
