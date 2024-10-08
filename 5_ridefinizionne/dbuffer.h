#ifndef DBUFFER_H
#define DBUFFER_H

#include <iostream>

class dbuffer
{
public:
    typedef unsigned int size_type;

private:
    size_type _size;
    int *_buffer;

public:
    dbuffer(); // costruttore di default FONDAMENTALE 1

    dbuffer(size_type size, int value = 0);

    dbuffer(const dbuffer &other); // costruttore di copia FONDAMENTALE 3

    dbuffer &operator=(const dbuffer &other); // assegnazione FONDAMENTALE 4

    ~dbuffer(); // distruttore FONDAMENTALE 2

    size_type get_size() const;

    int &value(size_type index);

    const int &value(size_type index) const;

    int &operator[](size_type index);

    const int &operator[](size_type index) const;

    void print() const;

    friend std::ostream &operator<<(std::ostream &os, const dbuffer &db);
};

std::ostream &operator<<(std::ostream &os, const dbuffer &db);

#endif