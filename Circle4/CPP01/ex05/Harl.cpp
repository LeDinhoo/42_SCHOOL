#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl destructor called" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "Harl is a very good guy" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Harl is a good guy" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Harl is a bad guy" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Harl is a very bad guy" << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*debugTab[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levelTab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levelTab[i])
		{
			(this->*debugTab[i])();
			return;
		}
	}
}