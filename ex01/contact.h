#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
public:
	Contact();
	Contact(const std::string& firstName, const std::string& lastName,
			const std::string& nickname, const std::string& phoneNumber,
			const std::string& darkestSecret);

	const std::string& firstName() const;
	const std::string& lastName() const;
	const std::string& nickname() const;
	const std::string& phoneNumber() const;
	const std::string& darkestSecret() const;

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif // CONTACT_H
