#ifndef DBUFFER_H
#define DBUFFER_H

#include <iostream>

class dbuffer
{
    unsigned int _size;
    int *_buffer;

public:
    dbuffer(); // costruttore di default FONDAMENTALE 1

    dbuffer(unsigned int size, int value = 0);

    dbuffer(const dbuffer &other); // costruttore di copia FONDAMENTALE 3

    dbuffer &operator=(const dbuffer &other); // assegnazione FONDAMENTALE 4

    ~dbuffer(); // distruttore FONDAMENTALE 2

    unsigned int get_size() const;

    int& value(unsigned int index);

    const int& value(unsigned int index) const;
    
    int& operator[](unsigned int index);

    const int& operator[](unsigned int index) const;

    void print() const;

    friend std::ostream &operator<<(std::ostream &os, const dbuffer &db);
};

std::ostream &operator<<(std::ostream &os, const dbuffer &db);

#endif