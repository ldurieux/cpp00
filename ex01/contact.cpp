#include "contact.h"

Contact::Contact()
{
}

Contact::Contact(const std::string &firstName, const std::string &lastName,
				 const std::string &nickname, const std::string &phoneNumber,
				 const std::string &darkestSecret) :
	_firstName(firstName),
	_lastName(lastName),
	_nickname(nickname),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
}

const std::string& Contact::firstName() const
{
	return _firstName;
}

const std::string& Contact::lastName() const
{
	return _lastName;
}

const std::string& Contact::nickname() const
{
	return _nickname;
}

const std::string& Contact::phoneNumber() const
{
	return _phoneNumber;
}

const std::string& Contact::darkestSecret() const
{
	return _darkestSecret;
}
