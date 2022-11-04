#include "ClapTrap.h"

ClapTrap::ClapTrap() : _name("defaultName"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name, unsigned int hitPoints, unsigned int energyPoints,
				   unsigned int attackDamage) :
		_name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	std::cout << "Setting all attributes ClapTrap constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Name ClapTrap constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = clapTrap;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
//	std::cout << "Copy assignment operator called" << std::endl;
	if (&clapTrap == this) return *this;

	_name = clapTrap.getName();
	_hitPoints = clapTrap.getHitPoints();
	_energyPoints = clapTrap.getEnergyPoints();
	_attackDamage = clapTrap.getAttackDamage();
	return *this;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::setName(const std::string &newName )
{
	_name = newName;
}
void ClapTrap::setHitPoints( unsigned int newHitPoints)
{
	_hitPoints = newHitPoints;
}
void ClapTrap::setEnergyPoints( unsigned int newEnergyPoints )
{
	_energyPoints = newEnergyPoints;
}
void ClapTrap::setAttackDamage( unsigned int  newAttackDamage )
{
	_attackDamage = newAttackDamage;
}
const std::string ClapTrap::getName() const
{
	return _name;
}
unsigned int  ClapTrap::getHitPoints() const
{
	return _hitPoints;
}
unsigned int  ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}
unsigned int  ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0)
		std::cout << getName() << " has no hit points left" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << getName() << " has no energy points left" << std::endl;
	else
	{
		--_energyPoints;
		std::cout << "ClapTrap " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << getName() << " has no hit points left" << std::endl;
	else
	{
		if (_hitPoints < amount)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		std::cout << "ClapTrap " << getName() << " takes " << amount
		<< " points of damage!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (getHitPoints() <= 0)
		std::cout << getName() << " has no hit points left" << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << getName() << " has no energy points left" << std::endl;
	else
	{
		_hitPoints += amount;
		--_energyPoints;
		std::cout << "ClapTrap " << getName() << " repairs " << amount
		<< " hit points back!" << std::endl;
	}
}




