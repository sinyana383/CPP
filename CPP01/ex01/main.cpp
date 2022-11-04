#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int N = 8;

	Zombie *horde = zombieHorde(N, std::string("Poludenica"));

	for (int i = 0; i < N; ++i)
		horde[i].announce();

	delete[] horde;
}
