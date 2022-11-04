#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

#include "WrongAnimal.h"

void printAnimalInfo(Animal &animal)
{
	std::cout << "AnimalInfo----------------" << std::endl;
	std::cout << "type: 	    "  << animal.getType() << std::endl;
	std::cout << "sound: 	    "; animal.makeSound();
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
	// Constructors and destructors check //////////
	const int size = 4;
	Animal *animals[size];
	for (int i = 0; i < size/2; ++i)
		animals[i] = new Dog;
	for (int i = size/2; i < size; ++i)
		animals[i] = new Cat;
	for (int i = 0; i < size; ++i)
		delete animals[i];

//	 copy, operator= check			///////////
	{
		Cat cat;
		cat.getBrain()->setIdea(0, "sleep");
		Cat copyCat(cat);

		std::cout << std::endl;

		std::cout << "Cat brain ideas address:		" << cat.getBrain()->getIdeas() << std::endl;
		std::cout << "Copycat brain ideas address:		" << copyCat.getBrain()->getIdeas() << std::endl;
		std::cout << "Cat brain ideas[0]:		" << cat.getBrain()->getIdeas()[0] << std::endl;
		std::cout << "Cat brain ideas[0]:		" << copyCat.getBrain()->getIdeas()[0] << std::endl;

		std::cout << std::endl;
	}
	std::cout << std::endl;

	Dog dog;
	dog.getBrain()->setIdea(0, "eat");
	Dog copyDog;
		copyDog = dog;
	std::cout << std::endl;

	std::cout << "Dog brain ideas address:		" << dog.getBrain()->getIdeas() << std::endl;
	std::cout << "Copydog brain ideas address:		" << copyDog.getBrain()->getIdeas() << std::endl;
	std::cout << "Dog brain ideas[0]:		" << dog.getBrain()->getIdeas()[0] << std::endl;
	std::cout << "Dog brain ideas[0]:		" << copyDog.getBrain()->getIdeas()[0] << std::endl;

	std::cout << std::endl;
	return (0);
}