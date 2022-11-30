#include <iostream>
#include "phonebook.h"

bool search(PhoneBook& phonebook)
{
	std::string strIdx;
	int			idx = 0;

	phonebook.listContact();
	while (strIdx.empty())
	{
		std::cout << "index: ";
		std::getline(std::cin, strIdx);
		if (std::cin.eof())
			return (false);
		try {
			idx = std::stoi(strIdx);
		} catch (...) {
			idx = -1;
		}
		if (idx < 0 || idx > phonebook.contactCount() - 1)
			strIdx.clear();
	}
	phonebook.displayContact(idx);
	return (true);
}

bool add(PhoneBook& phonebook)
{
	std::string strs[5];
	std::string labels[5] = {
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret",
	};

	for (int i = 0; i < 5; i++)
	{
		std::cout << labels[i] << ": ";
		std::getline(std::cin, strs[i]);
		if (std::cin.eof())
			return (false);
		if (strs[i].empty())
		{
			i--;
			continue ;
		}
	}
	phonebook.addContact(strs[0], strs[1], strs[2], strs[3], strs[4]);
	return (true);
}

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (command == "ADD")
			if (!add(phonebook))
				break ;
		if (command == "SEARCH")
			if (!search(phonebook))
				break ;
		if (command == "EXIT")
			break ;
	}
	return (0);
}
