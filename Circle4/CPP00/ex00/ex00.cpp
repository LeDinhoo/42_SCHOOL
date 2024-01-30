#include <iostream>

int main(int argc, char **argv)
{
	int i;
	int j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	j = 1;
	while (argv[j])
	{
		i = -1;
		while (argv[j][++i])
			std::cout << (char)std::toupper(argv[j][i]);
		j++;
	}
	std::cout << std::endl;
	return (0);
}