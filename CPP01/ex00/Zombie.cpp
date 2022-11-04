#include "Zombie.h"

Zombie::Zombie(const std::string& name) : _name(name)
{}
Zombie::~Zombie()
{
	std::cout << "destruction of " << _name << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

