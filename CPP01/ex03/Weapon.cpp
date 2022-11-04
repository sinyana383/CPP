#include "Weapon.h"

Weapon::Weapon(const std::string& newtype) : type(newtype){}

const std::string& Weapon::getType() { return ((const std::string&)type); }

void Weapon::setType(const std::string& newType) { type = newType; }
