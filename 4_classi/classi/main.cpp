#include <iostream>
#include <cassert>

#include "dbuffer.h"

int main()
{
    dbuffer db1;

    dbuffer db2(100);

    dbuffer db3(20, 7);

    int sz = db3.get_size();

    assert(sz == 20);

    dbuffer db4(db3); // costruttore di copia

    dbuffer db5 = db4; // costruttore di copia

    dbuffer db6;

    db6 = db5; // assegnazione

    db4[5] = 12;

    assert(db4[5] == 12);

    db3[6] = db4[5];

    assert(db3[6] == 12);

    db3.print();

    std::cout << db3;

    return 0;
}