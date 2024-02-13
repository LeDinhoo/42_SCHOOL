#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap " << this->_name << " is constructed from copy!" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " is destroyed!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(std::string const &target)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
	while (1)
	{
		this->_hitPoints -= 1;
		amount--;
		if (amount == 0)
			break;
		std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << std::endl;
		if (this->_hitPoints == 0)
		{
			std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
			break;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't be repaired!" << std::endl;
		return;
	}
	else if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points!" << std::endl;
		return;
	}
	else if (this->_hitPoints == 10)
	{
		std::cout << "ClapTrap " << this->_name << " has full hit points!" << std::endl;
		return;
	}
	else if (this->_hitPoints + amount <= 10)
	{
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << " hit points!" << std::endl;
		this->_hitPoints += amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't be repaired!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */