#include "ClapTrap.h"

void clapAttack(ClapTrap &attacker, ClapTrap &target)
{
	if (attacker.getEnergyPoints() > 0 && attacker.getHitPoints() > 0)
	{
		attacker.attack( target.getName());
		target.takeDamage(attacker.getAttackDamage());
	}
	else
		attacker.attack( target.getName());
}

int main()
{
	ClapTrap mavka("Mavka");
	ClapTrap noName;
	unsigned int	en = mavka.getEnergyPoints();

	mavka.setAttackDamage(7);
	for (unsigned int i = 0; i < en + 1; ++i)
		clapAttack(mavka, noName);

	noName.setHitPoints(1);
	en = noName.getEnergyPoints();
	for (unsigned int i = 0; i < en + 1; ++i)
		noName.beRepaired(1);

	noName.setAttackDamage(90);
	clapAttack(noName, mavka);

	return (0);
}