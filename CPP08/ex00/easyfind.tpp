#include "easyfind.h"


template<typename T>
typename T::iterator easyfind(T &cont, const int &toFind)
{
	// typename - помощь компилятору, для определения T::iterator как тип, а не переменая класса T.
	// имена класса парсятся компилятором всегда как переменные, а не как типы (nalysann)
	typename T::iterator result = find(std::begin(cont), std::end(cont), toFind);

	if (std::end(cont) == result) throw std::runtime_error("value not found");
	return result;
}