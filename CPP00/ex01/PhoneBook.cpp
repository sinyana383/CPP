#include "PhoneBook.h"

PhoneBook::PhoneBook(){ _freeContactIndex = 0; }

void PhoneBook::add()
{
	std::string prompts[5] = {"first name", "last name", \
	"nickname", "phone number", "darkest secret"};

	if (_freeContactIndex >= 8)
		_freeContactIndex = 0;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < 5; ++i)
	{
		std::string info;
		std::cout << prompts[i] << ": " << std::endl;
		while (info.empty())
		{
			std::getline(std::cin, info);
			if (std::cin.eof())			
				exit (EXIT_FAILURE);
		}
		_contacts[_freeContactIndex].setContactData(i, info);
	}
	++_freeContactIndex;
}
void PhoneBook::search()
{
	if (_contacts[0].getContactData(0).empty())
	{
		std::cout << "no contacts currently" << std::endl;
		return ;
	}

	std::string prompts[5] = {"first name", "last name", \
	"nickname", "phone number", "darkest secret"};

	std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "first name" << "|" \
	<< std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < 8; ++i)
	{
		if (_contacts[i].getContactData(0).empty())
			break ;
		std::cout << std::setw(10) << i << "|";
		for (int j = 0; j < 3; ++j)
		{
			std::string curString(_contacts[i].getContactData(j));
			if (curString.length() > 10)
			{
				curString.erase(10, curString.length() - 10);
				curString.at(9) = '.';
			}
			if (j < 2)
				std::cout << std::setw(10) << curString << "|";
			else
				std::cout << std::setw(10) << curString << std::endl;
		}
	}
	int index;
	std::cout << "chose existing index to display: " << std::endl;
	std::cin >> index;
	if (std::cin.eof())
		exit (EXIT_FAILURE);
	while (index < 0 || index > 7 || _contacts[index].getContactData(0).empty() || std::cin.fail())
	{
		std::cout << "error: index out of range or not a number" << std::endl;
		std::cout << "chose existing index: " << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> index;
		if (std::cin.eof())
			exit (EXIT_FAILURE);
	}
	for(int j = 0; j < 5; ++j)
		std::cout << prompts[j] << ": " << _contacts[index].getContactData(j) << std::endl;
}
