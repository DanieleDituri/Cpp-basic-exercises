#include <iostream>

#include "dbuffer.h"

int main()
{
    dbuffer::dynamic_buffer d; // = {0, nullptr};

    dbuffer::init(d);

    dbuffer::print(d);

    dbuffer::allocate(d, 5);
    dbuffer::print(d);
    std::cout << std::endl;

    dbuffer::set(d, 7);
    dbuffer::print(d);
    std::cout << std::endl;

    dbuffer::dynamic_buffer d2;
    dbuffer::init(d2);
    dbuffer::copy(d, d2);
    dbuffer::print(d);
    dbuffer::print(d2);
    std::cout << std::endl;

    dbuffer::set(d, 1);
    dbuffer::print(d);
    dbuffer::print(d2);
    std::cout << std::endl;

    dbuffer::deallocate(d);
    dbuffer::deallocate(d2);

    return 0;
}