#include "MutantStack.h"
#include <vector>
#include <list>

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;

	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}


	MutantStack<int> a;

	if (a.empty())
		std::cout << "MutantStack is empty" << std::endl;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	std::cout << a;
	a.top() = 10;
	std::cout << "MutantStack top is " << a.top() << std::endl;
	std::cout << a;

	std::cout << "pop " << a.top() << std::endl;
	a.pop();
	std::cout << a;

	std::stack<int>::container_type::iterator itBeg = a.begin();
	std::stack<int>::container_type::iterator itEnd = a.end();

	std::cout << "*(-1) each iterator" << std::endl;
	while (itBeg != itEnd)
	{
		*itBeg = *itBeg * -1;
		++itBeg;
	}
	std::cout << a;
}