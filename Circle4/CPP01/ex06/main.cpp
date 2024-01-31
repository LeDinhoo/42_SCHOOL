#include "Harl.hpp"

int levelFinder(char *argv)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (levels[i] == argv)
			return (i);
	return (-1);
}

void harlSwitch(char *argv, Harl &harl)
{
	switch (levelFinder(argv))
	{
	case 0:
		harl.complain("DEBUG");
		// fallthrough
	case 1:
		harl.complain("INFO");
		// fallthrough
	case 2:
		harl.complain("WARNING");
		// fallthrough
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char **argv)
{
	Harl harl;
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	else
		harlSwitch(argv[1], harl);
	return 0;
}