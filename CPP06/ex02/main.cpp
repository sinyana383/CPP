#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

Base * generate(void)
{
    srand(time(0));

    int a = rand();
    if (a % 3 == 0)
    {
//        std::cout << "A generated" << std::endl;
        return new A;
    }
    if (a % 3 == 1)
    {
//        std::cout << "B generated" << std::endl;
        return new B;
    }
//    std::cout << "C generated" << std::endl;
    return new C;
}

void identify(Base* p)
{
    if(dynamic_cast<A *>(p))
        std::cout << "Base *p class is A" << std::endl;
    else if(dynamic_cast<B *>(p))
        std::cout << "Base *p class is B" << std::endl;
    else if(dynamic_cast<C *>(p))
        std::cout << "Base *p class is C" << std::endl;
}

void identify(Base& p)
{
    try
    {
		(void)dynamic_cast<A&>(p);
        std::cout << "Base *p class is A" << std::endl;
    }
    catch (std::exception &e){}
    try
    {
		(void)dynamic_cast<B&>(p);
        std::cout << "Base *p class is B" << std::endl;
    }
    catch (std::exception &e){}
    try
    {
		(void)dynamic_cast<C&>(p);
        std::cout << "Base *p class is C" << std::endl;
    }
    catch (std::exception &e){}
}

int main()
{
    Base *b = generate();
    identify(b);
    identify(*b);
    delete b;
}