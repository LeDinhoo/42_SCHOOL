#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::debug(void)
{
	// A random complain of a guy in a restaurant
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I’m sorry, but I ordered this with extra bacon and you clearly did not give me extra bacon. I’ll have to ask you to leave." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now!" << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*debugTab[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levelTab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levelTab[i])
			(this->*debugTab[i])();
	}
}