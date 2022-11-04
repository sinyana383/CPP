#ifndef CPP07_ARRAY_H
#define CPP07_ARRAY_H
#include <stdexcept>

template<typename T>
class Array
{
private:
	T *_elements;
	unsigned int _size;
public:
	Array();
	Array(const Array &copy);
	~Array();
	Array& operator=(const Array &other);
	Array(unsigned int n);

	// const в конце гарантирует неизменение внутри класса
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const;
};

#endif //CPP07_ARRAY_H
