#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	Zombie *h = zombieHorde(5, "Alex");
	for (int i = 0; i < 5; i++)
	{
		h[i].announce();
	}
	delete[] h;
}