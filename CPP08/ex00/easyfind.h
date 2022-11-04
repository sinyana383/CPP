#ifndef CPP08_EASYFIND_H
#define CPP08_EASYFIND_H
#include <algorithm>
#include <iterator>
#include <stdexcept>

template<class T>
typename T::iterator easyfind(T &cont, const int &toFind);

#endif //CPP08_EASYFIND_H
