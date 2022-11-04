#ifndef CPP00_CONTACT_H
#define CPP00_CONTACT_H
#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
	std::string *_contact_data[5];
	std::string  _first_name;
	std::string  _last_name;
	std::string  _nickname;
	std::string  _phone_number;
	std::string  _darkest_secret;

public:
	Contact();
	void 		setContactData(int i, const std::string& data);
	std::string getContactData(int i);
};


#endif
