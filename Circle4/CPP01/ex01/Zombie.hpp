#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string);
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string);
};

#endif