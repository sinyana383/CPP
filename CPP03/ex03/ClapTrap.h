#ifndef CPP03_CLAPTRAP_H
#define CPP03_CLAPTRAP_H
#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string 		_name;
	unsigned int 		_hitPoints;
	unsigned int  		_energyPoints;
	unsigned int  		_attackDamage;
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const std::string& name, unsigned int hitPoints,
			 unsigned int energyPoints, unsigned int attackDamage);
	ClapTrap( const ClapTrap& clapTrap );
	~ClapTrap();
	ClapTrap& operator=( const ClapTrap& clapTrap );

	std::string 	getName() const;
	unsigned int 	getHitPoints() const;
	unsigned int 	getEnergyPoints() const;
	unsigned int  	getAttackDamage() const;
	void 			setName(const std::string &newName );
	void			setHitPoints( unsigned int newHitPoints);
	void 			setEnergyPoints( unsigned int  newEnergyPoints);
	void 			setAttackDamage( unsigned int  newAttackDamage );

	void attack(const std::string& target);
	void takeDamage(unsigned int  amount);
	void beRepaired(unsigned int  amount);
};


#endif //CPP03_CLAPTRAP_H
