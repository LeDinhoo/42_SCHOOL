#include <iostream>
#include <iomanip>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream inFile(filename.c_str());
	std::ofstream outFile((filename + ".replace").c_str());

	if (!inFile.is_open() || !outFile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		size_t pos = 0;
		pos = line.find(s1, pos);
		while (pos != std::string::npos)
		{
			line.insert(pos, s2);
			line.erase(pos + s2.length(), s1.length());
			pos = line.find(s1, pos + s2.length());
		}
		outFile << line << std::endl;
	}
	return 0;
}