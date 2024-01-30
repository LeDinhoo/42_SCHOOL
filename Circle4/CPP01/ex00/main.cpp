#include "Zombie.hpp"

Zombie *newZombie(std::string name);

void randomChump(std::string name);

int main()
{
	Zombie *a = newZombie("Alex");
	a->announce();
	randomChump("Frodo");
	delete a;
}