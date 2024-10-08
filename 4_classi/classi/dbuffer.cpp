#include <iostream>
#include <algorithm>
#include <cassert>

#include "dbuffer.h"

dbuffer::dbuffer() : _size(0), _buffer(nullptr)
{
#ifndef NDEBUG
    std::cout << "dbuffer()" << std::endl;
#endif
}

dbuffer::dbuffer(unsigned int size, int value) : _size(0), _buffer(nullptr)
{
    _buffer = new int[size];
    _size = size;

    for (unsigned int i = 0; i < _size; i++)
        _buffer[i] = value;

#ifndef NDEBUG
    std::cout << "dbuffer(" << size << ", " << value << ")" << std::endl;
#endif
}

dbuffer::dbuffer(const dbuffer &other) : _size(0), _buffer(nullptr)
{
    _buffer = new int[other._size];
    for (unsigned int i = 0; i < other._size; i++)
        _buffer[i] = other._buffer[i];
    _size = other._size;

#ifndef NDEBUG
    std::cout << "dbuffer(const dbuffer &)" << std::endl;
#endif
}

dbuffer &dbuffer::operator=(const dbuffer &other)
{
    if (this != &other)
    {
        dbuffer tmp(other);

        std::swap(_size, tmp._size);
        std::swap(_buffer, tmp._buffer);
    }

    return *this;
}

dbuffer::~dbuffer()
{
    delete[] _buffer;

    _buffer = nullptr;
    _size = 0;

#ifndef NDEBUG
    std::cout << "~dbuffer()" << std::endl;
#endif
}

unsigned int dbuffer::get_size() const
{
    return _size;
}

int &dbuffer::value(unsigned int index)
{
    assert(index < _size);

    return *(_buffer + index);
}

const int &dbuffer::value(unsigned int index) const
{
    assert(index < _size);

    return *(_buffer + index);
}

int &dbuffer::operator[](unsigned int index)
{
    assert(index < _size);

    return *(_buffer + index);
}

const int &dbuffer::operator[](unsigned int index) const
{
    assert(index < _size);

    return *(_buffer + index);
}

void dbuffer::print() const
{
    std::cout << "size: " << _size << std::endl;
    for (unsigned int i = 0; i < _size; i++)
        std::cout << _buffer[i] << " ";
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const dbuffer &db)
{
    os << "size: " << db.get_size() << std::endl;
    for (unsigned int i = 0; i < db.get_size(); i++)
        os << db[i] << " ";
    os << std::endl;

    return os;
}

/*
grazie al friend possiamo accedere ai membri privati della classe

std::ostream &operator<<(std::ostream &os, const dbuffer &db)
{
    os << "size: " << db._size << std::endl;
    for (unsigned int i = 0; i < db._size(); i++)
        os << db._buffer[i] << " ";
    os << std::endl;

    return os;
}
*/