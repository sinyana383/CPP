#include "Array.h"
#include <iostream>

template<typename T>
Array<T>::Array() : _elements(new T[0]), _size(0)
{}

template<typename T>
Array<T>::Array(const Array &copy) : _elements(new T[0]), _size(0)
{
	*this = copy;
}

template<typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n])
{
	if (n < 0) throw std::out_of_range("given size < 0");
	_size = n;
}

template<typename T>
Array<T>::~Array()
{
	delete []_elements;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this == &other) return *this;

	if (this->size() != other.size())
	{
		delete []this->_elements;

		this->_size = other.size();
		this->_elements = new T[other.size()];
	}
	for (unsigned int i = 0; i < other.size(); ++i)
		(*this)[i] = other[i];
	return *this;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->size()) throw std::out_of_range("index out of range");
	return _elements[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->size()) throw std::out_of_range("index out of range");
	return _elements[index];
}

template<typename T>
void printArray(Array<T> &array)
{
	for (unsigned int i = 0; i < array.size(); ++i)
		std::cout << " |" << array[i] << "| ";
}