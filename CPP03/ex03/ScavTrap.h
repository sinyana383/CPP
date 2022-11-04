#ifndef CPP03_SCAVTRAP_H
#define CPP03_SCAVTRAP_H
#include "ClapTrap.h"

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap( const ScavTrap& scavTrap );
	~ScavTrap();
	ScavTrap& operator=( const ScavTrap& scavTrap );

	void attack(const std::string& target);
	void guardGate();
};


#endif //CPP03_SCAVTRAP_H
