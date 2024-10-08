#include <iostream> //std::cout, std::endl
#include "file1.h" //funct1()

int main()
{
    std::cout << "Ciao!" << std::endl;

    funct1();

    int n = 0;

    std::cin >> n;

    if(std::cin.fail())
    {
        std::cout << "ERROR" << std::endl;
        return 0;
    }

    std::cout << "Hai inserito: " << n << std::endl;

    return 0;
}