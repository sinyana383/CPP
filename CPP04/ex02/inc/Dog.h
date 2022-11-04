#ifndef CPP04_DOG_H
#define CPP04_DOG_H
#include "Brain.h"
#include "Animal.h"

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog( const Dog& copy );
	virtual ~Dog();
	Dog& operator=( const Dog& variable );

	Brain *getBrain() const;

	void makeSound() const;
};

#endif
