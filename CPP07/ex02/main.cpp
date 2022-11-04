#include "Array.tpp"

int main()
{
	const Array<int> array01(5);
	// array[0] = 1;
	std::cout << array01[0] << std::endl;

	// Constructors/copy/=
	{
		Array<int> array0;
		printArray(array0);
		std::cout << "array0: ";
		std::cout << std::endl;

		Array<int> *array = new Array<int>(5);
		for (unsigned int i = 0; i < (*array).size(); ++i)
			(*array)[i] = static_cast<int>(i);
		std::cout << "array : ";
		printArray(*array);
		std::cout << std::endl;

		Array<int> array1(*array);
		delete array;
		std::cout << "array1: ";
		printArray(array1);
		std::cout << std::endl;

		array1[0] = -1;
		std::cout << "array1: ";
		printArray(array1);
		std::cout << std::endl;
		Array<int> array2;
		array2 = array1;
		std::cout << "array2: ";
		printArray(array2);
		std::cout << std::endl;
	}

	// exceptions /////////////////////////
	Array<int> array(5);
	try
	{
		array[5];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<std::string> arrayString; // пустой массив
	try
	{
		arrayString[0]; // в нем нет 0-ого элемента
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Char /////////////
	Array<std::string> arrayChar(5);
	for (unsigned int i = 0; i < (arrayChar).size(); ++i)
		(arrayChar)[i] = "ABC";
	std::cout << "array : ";
	printArray(arrayChar);
	std::cout << std::endl;
}
