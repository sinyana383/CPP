#include "FragTrap.h"

FragTrap::FragTrap()
{
	//из конструктора DiamondTrap он не идет в конструктор ClapTrap, скорее всего, потому что он теперь наследуется виртуально
	_name = "defaultName";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "Name FragTrap constructor called" << std::endl;
}
FragTrap::FragTrap( const FragTrap& fragTrap ) : ClapTrap(fragTrap)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	if (&fragTrap == this) return *this;

	ClapTrap *p1 = this;
	const ClapTrap *p2 = &fragTrap;
	*p1 = *p2;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0)
		std::cout << getName() << " has no hit points left" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << getName() << " has no energy points left" << std::endl;
	else
	{
		--_energyPoints;
		std::cout << "FragTrap " << getName() << " attacks " << target
				  << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
}
void FragTrap::highFivesGuys(void)
{
	if (getHitPoints() <= 0)
		std::cout << getName() << " has no hit points left" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << getName() << " has no energy points left" << std::endl;
	else
		std::cout << "a positive high fives request from " << getName() << std::endl;
}
