#include "Contact.h"

Contact::Contact()
{
	_contact_data[0] = &_first_name;
	_contact_data[1] = &_last_name;
	_contact_data[2] = &_nickname;
	_contact_data[3] = &_phone_number;
	_contact_data[4] = &_darkest_secret;
}

void 		Contact::setContactData(int i, const std::string& data){ *_contact_data[i] = data; }
std::string Contact::getContactData(int i){ return (*_contact_data[i]); }