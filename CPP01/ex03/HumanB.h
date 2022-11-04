#ifndef CPP01_HUMANB_H
#define CPP01_HUMANB_H
#include <string>
#include <iostream>
#include "Weapon.h"

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(const std::string& name); // const обязательно для строки типа "ASD"

	void attack();
	void setWeapon(Weapon& pWeapon);
};


#endif //CPP01_HUMANB_H
