#include "Zombie.h"

void randomChump( std::string name )
{
	Zombie zomb(name);	// exist only in current function

	zomb.announce();
}