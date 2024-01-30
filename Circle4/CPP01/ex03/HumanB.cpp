#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << "HumanB " << name << " created with ";
	std::cout << "(null)" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB object " << this->name << " destroyed" << std::endl;
}

void HumanB::attack(void)
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}