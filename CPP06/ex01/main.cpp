#include <cstdint>
#include <iostream>
#include "Data.h"

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main()
{
    Data d;
    d.intData = 12345;
    d.info = "AAA";
    d.num = 123.5f;

    uintptr_t raw = serialize(&d);
    Data *d1 = deserialize(raw);

    if (d1 == &d)
    {
        std::cout << &d << std::endl;
        std::cout << d1 << std::endl;
    }
    std::cout << std::endl;
    std::cout << d1->intData << std::endl;
    std::cout << d1->info << std::endl;
    std::cout << d1->num << std::endl;
}