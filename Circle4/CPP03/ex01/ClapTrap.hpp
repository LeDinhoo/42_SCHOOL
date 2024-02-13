#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{

public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap(ClapTrap const &src);
	ClapTrap &operator=(ClapTrap const &rhs);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

// std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#endif /* ******************************************************** CLAPTRAP_H */