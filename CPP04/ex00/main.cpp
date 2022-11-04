#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

#include "WrongAnimal.h"
#include "WrongCat.h"

void printAnimalInfo(Animal &animal)
{
	std::cout << "AnimalInfo----------------" << std::endl;
	std::cout << "type: "  << animal.getType() << std::endl;
	std::cout << "sound: "; animal.makeSound();
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
}

void printWrongAnimalInfo(WrongAnimal &wrongAnimal)
{
	std::cout << "wrongAnimalInfo----------------" << std::endl;
	std::cout << "type: "  << wrongAnimal.getType() << std::endl;
	std::cout << "sound: "; wrongAnimal.makeSound();
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
}

int main()
{
	// Subj //////////////////////////
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	// Subj WrongAnimal //////////////////////////
//	const WrongAnimal* meta = new WrongAnimal();
//	const WrongAnimal* i = new WrongCat();
//	std::cout << meta->getType() << " " << std::endl;
//	std::cout << i->getType() << " " << std::endl;
//	i->makeSound();
//	meta->makeSound();
//	WrongCat catt;
//	catt.makeSound();
//	delete meta;
//	delete i;

	// Animal //////////////////////////
//	Animal a;
//	Dog d;
//	Cat c;
//
//	printAnimalInfo(a);
//	printAnimalInfo(d);
//	printAnimalInfo(c);

	// WrongAnimal //////////////////////////
//	WrongAnimal a;
//	WrongCat c;
//
//	printWrongAnimalInfo(a);
//	printWrongAnimalInfo(c);

	return (0);
}