#ifndef CPP04_CAT_H
#define CPP04_CAT_H
#include "Brain.h"
#include "Animal.h"

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat( const Cat& copy );
	virtual ~Cat();
	Cat& operator=( const Cat& variable );

	Brain *getBrain() const;

	void makeSound() const;
};


#endif
