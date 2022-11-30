#include "phonebook.h"

PhoneBook::PhoneBook() :
	_contactCount(0),
	_currentContact(0)
{

}

void PhoneBook::addContact(const std::string& firstName, const std::string& lastName,
						   const std::string& nickname, const std::string& phoneNumber,
						   const std::string& darkestSecret)
{
	_contacts[_currentContact] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	_currentContact++;
	if (_currentContact >= 8)
		_currentContact = 0;
	if (_contactCount < 8)
		_contactCount++;
}

void PhoneBook::listContact() const
{
	std::cout << "|  index   |  first   |   last   |   nick   |" << std::endl;
	std::cout << "#----------#----------#----------#----------#" << std::endl;
	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << '|';
		std::cout << std::setw(10) << std::to_string(i) << '|';
		std::cout << std::setw(10) << formatString(_contacts[i].firstName()) << '|';
		std::cout << std::setw(10) << formatString(_contacts[i].lastName()) << '|';
		std::cout << std::setw(10) << formatString(_contacts[i].nickname()) << '|';
		std::cout << std::endl;
	}
	if (_contactCount != 0)
		std::cout << "#----------#----------#----------#----------#" << std::endl;
}

void PhoneBook::displayContact(int index) const
{
	const Contact &contact = _contacts[index];

	std::cout << std::setw(16) << "first name: " << contact.firstName() << std::endl;
	std::cout << std::setw(16) << "last name: " << contact.lastName() << std::endl;
	std::cout << std::setw(16) << "nickname: " << contact.nickname() << std::endl;
	std::cout << std::setw(16) << "phone number: " << contact.phoneNumber() << std::endl;
	std::cout << std::setw(16) << "darkest secret: " << contact.darkestSecret() << std::endl;
}

std::string PhoneBook::formatString(const std::string &str)
{
	std::string res;

	if (str.length() <= 10)
		return (str);
	for (int i = 0; i < 9; i++)
		res.push_back(str.data()[i]);
	res.push_back('.');
	return (res);
}

int PhoneBook::contactCount() const
{
	return _contactCount;
}
