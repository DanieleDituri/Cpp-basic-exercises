# include <iostream>

int main()
{

    int i1 = 100;

    int i2 = 200;

    int *ptr = nullptr;

    std::cout << "i1: " << i1 << std::endl;
    std::cout << "Indirirzzo di i1: " << &i1 << std::endl;

    std::cout << "i2: " << i2 << std::endl;
    std::cout << "Indirirzzo di i2: " << &i2 << std::endl;

    std::cout << "Indirizzo del puntatore: " << &ptr << std::endl;
    std::cout << "Contenuto del puntatore: " << ptr << std::endl;

    ptr = &i1;

    std::cout << "Contenuto del puntatore (indirizzo di i1): " << ptr << std::endl; // queste due righe sono equivalenti
    std::cout << "Indirizzo puntato: " << &(*ptr) << std::endl; // queste due righe sono equivalenti
    std::cout << "Contenuto puntato: " << *ptr << std::endl;

    ptr = &i2;

    ptr = ptr + 1;

    std::cout << "Contenuto del puntatore (indirizzo di i2 + 1): " << ptr << std::endl;

    ptr = &i2;
    
    *ptr = *ptr + 100;

    std::cout << "Contenuto puntato (i2 + 100): " << *ptr << std::endl;

    return 0;
}