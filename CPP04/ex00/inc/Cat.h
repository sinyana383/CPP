#ifndef CPP04_CAT_H
#define CPP04_CAT_H

#include "Animal.h"

class Cat : public Animal
{
public:
	Cat();
	Cat( const Cat& copy );
	~Cat();
	Cat& operator=( const Cat& variable );

	void makeSound() const;
};


#endif
