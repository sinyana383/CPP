#include "Zombie.h"

void Zombie::setName(std::string &name) { _name = name; }

Zombie::Zombie() : _name("defaultName")
{}

Zombie::~Zombie()
{
	std::cout << "destruction of " << _name << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

