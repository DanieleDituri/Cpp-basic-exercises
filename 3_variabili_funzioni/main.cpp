#include <iostream>

#include "stringhec.h"

/**
 * @brief Funzione main.
 * 
 * funzione principale del programma
 * 
 * @param argc Il numero di argomenti passati alla riga di comando.
 * @param argv Un array di puntatori alle stringhe degli argomenti passati alla riga di comando.
 * @return Il valore di uscita del programma.
 */
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        stampa(argv[1]);
        std::cout << argv[1] << std::endl;

        std::cout << "La lunghezza della stringa è: " << lunghezza(argv[1]) << std::endl;

        inverti(argv[1]);
        std::cout << "La stringa invertita è: " << argv[1] << std::endl;

        char *copia = clona(argv[1]);

        std::cout << "La copia della stringa è: " << copia << std::endl;

        delete[] copia;
        copia = nullptr;

        const char *cat = concatena(argv[1], "stringa");

        std::cout << "La stringa concatenata è: " << cat << std::endl;

        delete[] cat;
        cat = nullptr;
    }
    else
        std::cout << "Passare una stringa" << std::endl;

    return 0;
}