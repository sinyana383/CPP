#include "easyfind.tpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	{
		const unsigned int size = 10;
		std::vector<int> vector1;

		for (int i = size - 1; i >= 0; --i)
			vector1.push_back(i);
		vector1.push_back(5);

		for (unsigned i = 0; i < vector1.size(); ++i)
			std::cout << vector1[i] << " ";
		std::cout << std::endl;

		std::vector<int>::iterator toDel = easyfind(vector1, 5);
		vector1.erase(toDel);

		for (unsigned i = 0; i < vector1.size(); ++i)
			std::cout << vector1[i] << " ";
		std::cout << std::endl;

		try
		{
			std::vector<int>::iterator toDel = easyfind(vector1, 11);
			vector1.erase(toDel);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		const unsigned int size = 10;
		std::list<int> vector1;

		for (int i = size - 1; i >= 0; --i)
			vector1.push_back(i);
		vector1.push_back(5);

		std::list<int>::iterator itBeg = vector1.begin();
		std::list<int>::iterator itEnd = vector1.end();

		while (itBeg != itEnd)
		{
			std::cout << *(itBeg) << " ";
			++itBeg;
		}
		std::cout << std::endl;

		std::list<int>::iterator toDel = easyfind(vector1, 5);
		vector1.erase(toDel);
		
		itBeg = vector1.begin();
		itEnd = vector1.end();

		while (itBeg != itEnd)
		{
			std::cout << *(itBeg) << " ";
			++itBeg;
		}
		std::cout << std::endl;

		try
		{
			std::list<int>::iterator toDel = easyfind(vector1, 11);
			vector1.erase(toDel);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
