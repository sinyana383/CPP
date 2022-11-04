#ifndef CPP07_ITER_H
#define CPP07_ITER_H
#include <iostream>

template<typename T>
void iter(T *array, int length, void (* fun)(T const &))
{
	for (int i = 0; i < length; ++i)
		fun(array[i]);
}

template< typename T, typename F>
void example(T const & element)
{
	std::cout << static_cast<F>(element) << " ";
}

#endif
