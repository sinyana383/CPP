#ifndef CPP04_DOG_H
#define CPP04_DOG_H

#include "Animal.h"

class Dog : public Animal
{
public:
	Dog();
	Dog( const Dog& copy );
	~Dog();
	Dog& operator=( const Dog& variable );

	void makeSound() const;
};


#endif
