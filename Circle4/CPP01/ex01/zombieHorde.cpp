#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int i = 0;

	Zombie *h = new Zombie[N];
	while (i < N)
	{
		h[i].setName(name);
		i++;
	}
	return (h);
}