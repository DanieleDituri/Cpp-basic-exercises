#include <iostream>
#include <cstring>
#include <sstream>

struct pippo
{
    char c1;
    int i;
    char c2;
};

struct __attribute__((packed)) pippo_packed
{
    char c1;
    int i;
    char c2;
};

int main(int argc, char **argv)
{

    /*
    for (int i = 0 ; i < argc ; i++)
        std::cout << "Argomento " << i << ": " << argv[i] << std::endl;
    */
    if (argv[1] != nullptr)
    {
        std::cout << "Argomento 1: " << argv[1] << std::endl;

        std::cout << atoi(argv[1]) << std::endl;

        std::stringstream ss(argv[1]);

        int v;

        ss >> v;

        std::cout << v << std::endl;

        bool b;

        ss >> b;

        std::cout << b << std::endl;
    }

    std::cout << sizeof(pippo) << std::endl;

    std::cout << sizeof(pippo_packed) << std::endl;

    int v = 2;

    int &vr = v;

    std::cout << "Indirizzo di v: " << &v << std::endl;
    std::cout << "Indirizzo di vr: " << &vr << std::endl;

    const int *pv = nullptr;

    pv = &v;

    // *pv = 90; Errore di compilazione perché pv è un puntatore a costante

    *(const_cast<int *>(pv)) = 90;

    return 0;
}