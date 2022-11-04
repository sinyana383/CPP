#include "ScavTrap.h"

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

	ScavTrap triglav("Triglav");

	ScavTrap sudgen(triglav);
	sudgen.setName("Sudgenica");

	printAllAttributes(triglav);
	printAllAttributes(sudgen);
	sudgen.guardGate();

	energy = sudgen.getEnergyPoints();
	for (unsigned int i = 0; i < energy + 1; ++i)
		sudgen.beRepaired(1);

	printAllAttributes(sudgen);

	energy = triglav.getEnergyPoints();
	for (unsigned int i = 0; i < energy + 1; ++i)
		clapAttack(triglav, sudgen);

	printAllAttributes(triglav);
	printAllAttributes(sudgen);

	clapAttack(sudgen, triglav);
	sudgen.guardGate();

	return (0);
}