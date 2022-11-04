#include "HumanA.h"

HumanA::HumanA(const std::string& name, Weapon &weapon) : weapon(weapon), name(name){}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

