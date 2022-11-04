#include "HumanB.h"

HumanB::HumanB(const std::string& name) : name(name)
{
	this->weapon = nullptr;
}

void HumanB::setWeapon(Weapon& pWeapon) { this->weapon = &pWeapon; }
void HumanB::attack()
{
	if (weapon == nullptr)
		return ;
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
