/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 07:34:33 by hdupuy            #+#    #+#             */
/*   Updated: 2024/02/12 15:59:28 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap clap("Zozio");
	ScavTrap clap2(clap);

	clap.attack("my dick");
	clap.takeDamage(7);
	clap.beRepaired(10);
	clap.guardGate();

	return 0;
}
