#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string &name)
{
	// По сути атрибутов 5: 4 из ClapTrap и 1 - свой
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Name DiamondTrap constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap)
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	if (&diamondTrap == this) return *this;

	ClapTrap *p1 = this;
	const ClapTrap *p2 = &diamondTrap;
	*p1 = *p2;
	return *this;
}


void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	if (getHitPoints() <= 0)
		std::cout << getName() << " has no hit points left" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << getName() << " has no energy points left" << std::endl;
	else
		std::cout << _name << "'s clap_name is " << getName() << std::endl;
}
