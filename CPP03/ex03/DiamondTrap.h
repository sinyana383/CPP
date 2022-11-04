#ifndef CPP03_DIAMONDTRAP_H
#define CPP03_DIAMONDTRAP_H
#include "string"
#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	// _name from ClapTrap
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap( const DiamondTrap& diamondTrap );
	~DiamondTrap();
	DiamondTrap& operator=( const DiamondTrap& diamondTrap );

	void attack(const std::string& target);
	void whoAmI();
};


#endif //CPP03_DIAMONDTRAP_H
