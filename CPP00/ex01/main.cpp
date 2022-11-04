#include "PhoneBook.h"

int main()
{
	std::string input;
	PhoneBook	phoneBook;

	do{
		std::cout << "type ADD, SEARCH or EXIT: " << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			exit (1);
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.search();
	} while (input != "EXIT");
}