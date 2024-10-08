#include "dbuffer.hpp"

int main(int argc, char *argv[])
{
    dbuffer<int> di;

    dbuffer<double> db;

    dbuffer<int>::iterator b, e;

    b = di.begin();
    e = di.end();

    for (; b != e ; ++b)
    {
        
    }
  
    return 0;
}