/**
  @file dbuffer.cpp

  @brief File cpp della classe dbuffer

  File di definizioni della classe dbuffer
*/

#include "dbuffer.h"
#include <iostream> // std::cout
#include <cassert>
#include <algorithm> // std::swap

dbuffer::dbuffer() : _size(0), _buffer(nullptr)
{ // initialization list
#ifndef NDEBUG
  std::cout << "dbuffer::dbuffer()" << std::endl;
#endif
}

dbuffer::dbuffer(size_type size) : _size(0), _buffer(nullptr)
{
  _buffer = new int[size];
  _size = size;

#ifndef NDEBUG
  std::cout << "dbuffer::dbuffer(size_type size)" << std::endl;
#endif
}

dbuffer::~dbuffer()
{
  delete[] _buffer;

  _buffer = nullptr;
  _size = 0;

#ifndef NDEBUG
  std::cout << "dbuffer::~dbuffer()" << std::endl;
#endif
}

int &dbuffer::value(size_type index)
{
  assert(index < _size);

  return _buffer[index];
}

const int &dbuffer::value(size_type index) const
{
  assert(index < _size);

  return _buffer[index];
}

int &dbuffer::operator[](size_type index)
{
  assert(index < _size);

  return _buffer[index];
}

const int &dbuffer::operator[](size_type index) const
{
  assert(index < _size);

  return _buffer[index];
}

dbuffer::size_type dbuffer::size(void) const
{
  return _size;
}

void dbuffer::print(void) const
{
  std::cout << _size << " [ ";
  for (size_type i = 0; i < _size; ++i)
    std::cout << _buffer[i] << " ";
  std::cout << "]" << std::endl;
}

dbuffer::dbuffer(size_type size, int value) : _size(0), _buffer(nullptr)
{
  _buffer = new int[size];
  _size = size;

  fill(value);

#ifndef NDEBUG
  std::cout << "dbuffer::dbuffer(size_type  size, int value)" << std::endl;
#endif
}

void dbuffer::fill(int value)
{
  for (size_type i = 0; i < _size; ++i)
    _buffer[i] = value;
}

dbuffer::dbuffer(const dbuffer &other) : _size(0), _buffer(nullptr)
{
  _buffer = new int[other._size];

  for (size_type i = 0; i < other._size; ++i)
    _buffer[i] = other._buffer[i];

  _size = other._size;

#ifndef NDEBUG
  std::cout << "dbuffer::dbuffer(const dbuffer &other)" << std::endl;
#endif
}

dbuffer &dbuffer::operator=(const dbuffer &other)
{
  if (this != &other)
  {                     // controllo auto-assegnamento
    dbuffer tmp(other); // creo una copia dei dati
    this->swap(tmp);    // scambio gli stati/dati
  } // tmp, con i vecchi dati , viene rimosso automaticamente dalla memoria

#ifndef NDEBUG
  std::cout << "dbuffer::operator=(const dbuffer &other)" << std::endl;
#endif

  return *this; // ritorno me stesso // a=b=c;
}

void dbuffer::swap(dbuffer &other)
{
  std::swap(this->_size, other._size);
  std::swap(this->_buffer, other._buffer);
}

std::ostream &operator<<(std::ostream &os, const dbuffer &db)
{
  os << db._size << " [ ";
  for (dbuffer::size_type i = 0; i < db.size(); ++i)
    os << db[i] << " ";
  os << "]";

  return os;
}

// somma di dbuffer+int
dbuffer dbuffer::operator+(int rhs) const
{
  dbuffer result(*this);

  for (size_type i = 0; i < _size; ++i)
    result._buffer[i] += rhs;

  return result;
}

// prodotto scalare tra due dbuffer: dbuffer+dbuffer
long int dbuffer::operator%(const dbuffer &rhs) const
{
  assert(_size == rhs._size);

  long int result = 0;

  for (size_type i = 0; i < _size; ++i)
    result += _buffer[i] * rhs[i];

  return result;
}

// somma dei valori contenuti nell'array: *dbuffer
long int dbuffer::operator*(void) const
{
  long int result = 0;

  for (size_type i = 0; i < _size; ++i)
    result += _buffer[i];

  return result;
}

// somma 1 a ogni cella dell'array:
// a = ++i : prefisso (ritorna il valore modificato)
dbuffer &dbuffer::operator++(void)
{ // ++(++i)
  for (size_type i = 0; i < _size; ++i)
    _buffer[i] += 1;

  return *this;
}

// somma 1 a ogni cella dell'array:
// a = i++ : postfisso /ritorna il vecchio valore)
dbuffer dbuffer::operator++(int)
{
  dbuffer result(*this);

  for (size_type i = 0; i < _size; ++i)
    _buffer[i] += 1;

  return result;
}

dbuffer::operator unsigned int() const
{
  return *(*this);
}

// somma tra due dbuffer: dbuffer+dbuffer
dbuffer operator+(const dbuffer &lhs, const dbuffer &rhs)
{
  assert(lhs.size() == rhs.size());

  dbuffer tmp(lhs);

  for (dbuffer::size_type i = 0; i < lhs.size(); ++i)
  {
    tmp[i] += rhs[i];
  }

  return tmp;
}

// somma tra un intero e un dbuffer: int+dbuffer
dbuffer operator+(int lhs, const dbuffer &rhs)
{
  dbuffer tmp(rhs);

  for (dbuffer::size_type i = 0; i < rhs.size(); ++i)
  {
    tmp[i] += lhs;
  }

  return tmp;
}

// dbuffer+=dbuffer
dbuffer &operator+=(dbuffer &lhs, const dbuffer &rhs)
{
  assert(lhs.size() == rhs.size());

  for (dbuffer::size_type i = 0; i < rhs.size(); ++i)
  {
    lhs[i] += rhs[i];
  }

  return lhs;
}

// cambio segno: -dbuffer
dbuffer operator-(const dbuffer &lhs)
{
  dbuffer res(lhs);
  for (dbuffer::size_type i = 0; i < res.size(); ++i)
  {
    res[i] = -res[i];
  }

  return res;
}
