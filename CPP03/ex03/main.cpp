#include "DiamondTrap.h"

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

void printAllAttributes(const ClapTrap &cl)
{
	std::cout << std::endl;
	std::cout << "name: " 			<< cl.getName() << std::endl;
	std::cout << "hitPoints: " 		<< cl.getHitPoints() << std::endl;
	std::cout << "energyPoints: " 	<< cl.getEnergyPoints() << std::endl;
	std::cout << "attackDamage: " 	<< cl.getAttackDamage() << std::endl;
	std::cout << std::endl;
}

int main()
{
	unsigned int energy = 0;

	DiamondTrap perun("Perun");
	printAllAttributes(perun);
	perun.guardGate();
	perun.highFivesGuys();
	perun.whoAmI();
	energy = perun.getEnergyPoints();
	for (unsigned int i = 0; i < energy + 1; ++i)
		perun.attack("void");
	printAllAttributes(perun);
	perun.whoAmI();

	ClapTrap VOID("Void");
	printAllAttributes(VOID);
	energy = VOID.getEnergyPoints();
	for (unsigned int i = 0; i < energy/2; ++i)
		VOID.beRepaired(1);
	printAllAttributes(VOID);

	energy = VOID.getEnergyPoints();
	for (unsigned int i = 0; i < energy + 1; ++i)
		clapAttack(VOID, perun);
	printAllAttributes(VOID);
	printAllAttributes(perun);
	return (0);
}