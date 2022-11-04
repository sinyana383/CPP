#include "FragTrap.h"

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

	FragTrap veles("Veles");
	FragTrap rod;
	rod = veles;
	rod.setName("Rod");

	printAllAttributes(veles);
	printAllAttributes(rod);
	rod.highFivesGuys();

	energy = rod.getEnergyPoints();
	for (unsigned int i = 0; i < energy + 1; ++i)
		rod.beRepaired(1);

	printAllAttributes(rod);
	rod.highFivesGuys();

	energy = veles.getEnergyPoints();
	for (unsigned int i = 0; i < energy + 1; ++i)
		clapAttack(veles, rod);

	printAllAttributes(veles);
	printAllAttributes(rod);

	clapAttack(rod, veles);
	rod.highFivesGuys();

	return (0);
}