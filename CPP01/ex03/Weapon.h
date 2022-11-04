#ifndef CPP01_WEAPON_H
#define CPP01_WEAPON_H
#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon(const std::string& newtype);
	const std::string& getType();
	void setType(const std::string& newType);
};


#endif
