#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
	int contactCount;

public:
	Phonebook();
	~Phonebook();
	void addContact();
	void searchContact();
	std::string getInput(std::string prompt);
};

#endif