#include <iostream>
#include <string>

int main()
{
	std::string myString = "HI THIS IS BRAIN";
	std::string *stringPTR = &myString;
	std::string &stringREF = myString;

	std::cout << "Memory Address of the String Variable: " << &myString << std::endl;
	std::cout << "Memory Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "\nValue of the String Variable: " << myString << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
