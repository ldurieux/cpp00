#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "contact.h"

class PhoneBook
{
public:
	PhoneBook();

	void addContact(const std::string& firstName, const std::string& lastName,
					const std::string& nickname, const std::string& phoneNumber,
					const std::string& darkestSecret);
	void listContact() const;
	void displayContact(int index) const;

	int contactCount() const;

private:
	static std::string formatString(const std::string& str);

	Contact _contacts[8];
	int		_contactCount;
	int		_currentContact;
};

#endif // PHONEBOOK_H
