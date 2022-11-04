#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap("defaultName", 100, 50, 20)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "Name ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	if (&scavTrap == this) return *this;

	ClapTrap *p1 = this;
	const ClapTrap *p2 = &scavTrap;
	*p1 = *p2;
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}


void ScavTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0)
		std::cout << getName() << " has no hit points left" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << getName() << " has no energy points left" << std::endl;
	else
	{
		--_energyPoints;
		std::cout << "ScavTrap " << getName() << " attacks " << target
				  << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
}
void ScavTrap::guardGate()
{
	if (getHitPoints() <= 0)
		std::cout << getName() << " has no hit points left" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << getName() << " has no energy points left" << std::endl;
	else
		std::cout << getName() << " is now in Gate keeper mode" << std::endl;
}
