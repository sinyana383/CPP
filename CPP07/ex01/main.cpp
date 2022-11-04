#include "iter.h"

void oddEven(const int &a)
{
	if (a % 2 == 0)
		std::cout << "e ";
	else
		std::cout << "o ";
}

int main()
{
	const int size = 127 - 32;
	int array[size] = {};

	int j = 32;
	for (int i = 0; i < size; ++i)
		array[i] = j++;

	iter(array, size, example<int, char>);
	std::cout << std::endl;
	iter(array, size, oddEven);
	std::cout << std::endl;
	iter(array, size, example<int, float>);
	std::cout << std::endl;
}