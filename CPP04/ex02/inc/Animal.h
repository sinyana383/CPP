#ifndef CPP04_ANIMAL_H
#define CPP04_ANIMAL_H
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal( const Animal& copy );
	virtual ~Animal();
	Animal& operator=( const Animal& variable );
	Animal( const std::string &otherType );

	const std::string &getType() const;

	virtual void makeSound() const = 0;
};

#endif
