#include "dbuffer.hpp"

int main(int argc, char *argv[])
{
    dbuffer<int> di;

    std::cout << di << std::endl;

    dbuffer<double> db;

    std::cout << db << std::endl;

    dbuffer<dbuffer<int> > dx;

    std::cout << dx << std::endl;

    dbuffer<dbuffer<int> > dy(10, dbuffer<int>(5, 3));

    std::cout << dy << std::endl;

    return 0;
}