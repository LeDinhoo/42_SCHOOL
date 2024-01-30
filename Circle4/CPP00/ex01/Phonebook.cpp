#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->contactCount = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::addContact()
{
	if (this->contactCount == 8)
		std::cout << "Phonebook is full." << std::endl;
	else
	{
		this->contacts[this->contactCount].setFirstName(this->getInput("Enter first name: "));
		this->contacts[this->contactCount].setLastName(this->getInput("Enter last name: "));
		this->contacts[this->contactCount].setNickname(this->getInput("Enter nickname: "));
		this->contacts[this->contactCount].setPhoneNumber(this->getInput("Enter phone number: "));
		this->contacts[this->contactCount].setDarkestSecret(this->getInput("Enter darkest secret: "));
		this->contactCount++;
	}
}

void Phonebook::searchContact()
{
	int i;
	int index;
	std::string input;

	if (this->contactCount == 0)
		std::cout << "Phonebook is empty." << std::endl;
	else
	{
		std::cout << std::setw(10) << "Index" << "|";
		std::cout << std::setw(10) << "First name" << "|";
		std::cout << std::setw(10) << "Last name" << "|";
		std::cout << std::setw(10) << "Nickname" << std::endl;
		i = 0;
		while (i < this->contactCount)
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << this->contacts[i].getFirstName() << "|";
			std::cout << std::setw(10) << this->contacts[i].getLastName() << "|";
			std::cout << std::setw(10) << this->contacts[i].getNickname() << std::endl;
			i++;
		}
		std::cout << "Enter an index: ";
		std::getline(std::cin, input);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			index = input[0] - '0';
			std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
			std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
			std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
			std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
		}
		else
			std::cout << "Invalid index." << std::endl;
	}
}

std::string Phonebook::getInput(std::string prompt)
{
	std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);
	return (input);
}