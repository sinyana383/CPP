#ifndef CPP08_MUTANTSTACK_H
#define CPP08_MUTANTSTACK_H
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack<T>(){};
	MutantStack<T>(MutantStack<T> const &copy){ *this = copy; }
	~MutantStack<T>(){ }
	MutantStack<T> &operator=(MutantStack<T> const &copy)
	{
		if (this == &copy) return *this;

		std::stack<T> *stackPart1 = this;
		std::stack<T> *stackPart2 = &copy;
		*stackPart1 = *stackPart2;
		return *this;
	}

	// 	   стек с типом контейнера::сам контейнер ::итератор
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		// c - видимо, сокращение от container_type
		return std::stack<T>::c.begin();
	}
	iterator end()
	{
		return std::stack<T>::c.end();
	}
};

template<typename T>
std::ostream &operator<<(std::ostream &o, MutantStack<T> &m)
{
	for (unsigned long i = 1; i <= m.size(); ++i)
		std::cout << *(m.end() - i) << std::endl;
	std::cout << std::endl;
	return o;
}

#endif //CPP08_MUTANTSTACK_H
