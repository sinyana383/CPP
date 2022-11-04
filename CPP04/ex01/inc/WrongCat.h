#ifndef CPP04_WRONGCAT_H
#define CPP04_WRONGCAT_H
#include "WrongAnimal.h"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat( const WrongCat& copy );
	~WrongCat();
	WrongCat& operator=( const WrongCat& variable );

	void makeSound() const;
};


#endif
