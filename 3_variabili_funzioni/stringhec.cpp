#include <iostream>

#include "stringhec.h"

void stampa(const char *str)
{

    for (; *str != '\0' ; str++)
        std::cout << *str << std::endl;
}

int lunghezza(const char *str)
{
    const char *end = str;

    while (*end != '\0')
        end++;

    return end - str;
}

void inverti(char *str)
{
    int L = lunghezza(str);

    int i = 0;

    for (; i < L / 2; i++)
        std::swap(str[i], str[L - i - 1]);

}

char *clona(const char *str)
{
    char *copia = nullptr;

    copia = new char[lunghezza(str) + 1];

    for (int i = 0 ; str[i] != '\0' ; i++)
        copia[i] = str[i];

    copia[lunghezza(str)] = '\0';

    return copia;
}

char *concatena(const char *str1, const char *str2)
{
    int L1 = lunghezza(str1);
    int L2 = lunghezza(str2);

    char * out = new char[L1 + L2 + 1];

    for (int i = 0 ; i < L1 ; i++)
        out[i] = str1[i];

    for (int i = 0 ; i < L2 + 1 ; i++)
        out[L1 + i] = str2[i];

    return out;
}



const char *cerca(const char *s1, const char *st)
{

}
