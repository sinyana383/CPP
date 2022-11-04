#ifndef CPP01_ZOMBIE_H
#define CPP01_ZOMBIE_H
#include <string>
#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie(const std::string& name);
	~Zombie();
	void announce( void );
};


#endif
