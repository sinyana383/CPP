#ifndef CPP00_PHONEBOOK_H
#define CPP00_PHONEBOOK_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.h"

class PhoneBook
{
private:
	Contact _contacts[8];
	int 	_freeContactIndex;
public:
	PhoneBook();
	void add();
	void search();
};


#endif