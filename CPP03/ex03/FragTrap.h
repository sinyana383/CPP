#ifndef CPP03_FRAGTRAP_H
#define CPP03_FRAGTRAP_H
#include "ClapTrap.h"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap( const FragTrap& fragTrap );
	~FragTrap();
	FragTrap& operator=( const FragTrap& fragTrap );

	void attack(const std::string& target);
	void highFivesGuys(void);
};


#endif //CPP03_FRAGTRAP_H
