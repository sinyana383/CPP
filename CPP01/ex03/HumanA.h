#ifndef CPP01_HUMANA_H
#define CPP01_HUMANA_H
#include <string>
#include <iostream>
#include "Weapon.h"

class HumanA
{
private:

	Weapon& weapon;
	std::string name;
public:
	HumanA(const std::string& name, Weapon &weapon);
	void attack();
};


#endif
