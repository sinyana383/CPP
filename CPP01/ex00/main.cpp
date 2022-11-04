#include "Zombie.h"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	randomChump(std::string("Hors"));

	// allocation on the heap - when we need it to the SPECIFIC MOMENT
	Zombie *perun_zomb = newZombie(std::string("Perun"));
	perun_zomb->announce();
	delete perun_zomb;	// SPECIFIC MOMENT

	// allocation on the stack - when we need during all the program
	Zombie makosh_zomb(std::string("Makosh"));
	makosh_zomb.announce();

}