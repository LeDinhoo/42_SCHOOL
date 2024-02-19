/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:48:50 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/19 12:16:30 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Directives de préprocesseur pour éviter les inclusions multiples
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

// Inclusions de bibliothèques nécessaires
#include <iomanip>
#include <iostream>
#include <string>

// Déclaration de la classe Animal
class AAnimal
{
  public:
	// Constructeurs et destructeur
	AAnimal ();						// Constructeur par défaut
	AAnimal ( std::string type );	// Constructeur avec paramètre
	AAnimal ( AAnimal const &src ); // Constructeur de copie
	virtual ~AAnimal ();			// Destructeur virtuel

	// Surcharge de l'opérateur d'assignation
	AAnimal &operator= ( AAnimal const &rhs );

	// Méthodes publiques
	std::string getType () const;		 // Méthode pour obtenir le type
	virtual void makeSound () const = 0; // Fonction virtuelle pure

  protected:
	// Attribut protégé représentant le type de l'animal
	std::string type;
};

// Surcharge de l'opérateur de sortie pour afficher un AAnimal
std::ostream &operator<< ( std::ostream &o, AAnimal const &i );

// Fin de la directive de préprocesseur
#endif /* ANIMAL_HPP */
