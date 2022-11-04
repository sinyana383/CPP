#ifndef CPP04_WRONGANIMAL_H
#define CPP04_WRONGANIMAL_H
#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal( const WrongAnimal& copy );
	virtual ~WrongAnimal();
	WrongAnimal& operator=( const WrongAnimal& variable );
	WrongAnimal( const std::string &otherType );

	const std::string &getType() const;

	void makeSound() const;
};


#endif //CPP04_WRONGANIMAL_H
