#ifndef DBUFFER_H
#define DBUFFER_H

#include <iostream>
#include <cassert>
#include <algorithm>

template <typename T>
class dbuffer
{
public:
    typedef unsigned int size_type;
    typedef T value_type;

    dbuffer() : _size(0), _buffer(nullptr)
    {
#ifndef NDEBUG
        std::cout << "dbuffer::dbuffer()" << std::endl;
#endif
    }

    explicit dbuffer(size_type size) : _size(0), _buffer(nullptr)
    {
        _buffer = new value_type[size];
        _size = size;

#ifndef NDEBUG
        std::cout << "dbuffer::dbuffer(size_type)" << std::endl;
#endif
    }

    dbuffer(size_type size, const value_type &value) : _size(0), _buffer(nullptr)
    {
        _buffer = new value_type[size];

        try
        {
            for (size_type i = 0; i < _size; ++i)
                _buffer[i] = value;
        }
        catch (...)
        {
            delete[] _buffer;
            _buffer = nullptr;
            throw;
        }

        _size = size;

#ifndef NDEBUG
        std::cout << "dbuffer::dbuffer(size_type, T)" << std::endl;
#endif
    }

    dbuffer(const dbuffer &other) : _size(0), _buffer(nullptr)
    {
        _buffer = new value_type[other._size];

        for (size_type i = 0; i < other._size; ++i)
            _buffer[i] = other._buffer[i];

        _size = other._size;

#ifndef NDEBUG
        std::cout << "dbuffer::dbuffer(const dbuffer &other)" << std::endl;
#endif
    }

    dbuffer &operator=(const dbuffer &other)
    {
        if (this != &other)
        {
            dbuffer tmp(other);
            this->swap(tmp);
        }

#ifndef NDEBUG
        std::cout << "dbuffer::operator=(const dbuffer &other)" << std::endl;
#endif

        return *this;
    }

    ~dbuffer()
    {
        delete[] _buffer;

        _buffer = nullptr;
        _size = 0;

#ifndef NDEBUG
        std::cout << "dbuffer::~dbuffer()" << std::endl;
#endif
    }

    value_type gat_value(size_type index) const
    {
        assert(index < _size);

        return *(_buffer + index);
    }

    void set_value(size_type index, const value_type &value)
    {
        assert(index < _size);

        *(_buffer + index) = value;
    }

    value_type &value(size_type index)
    {
        assert(index < _size);

        return *(_buffer + index);
    }

    const value_type &value(size_type index) const
    {
        assert(index < _size);

        return *(_buffer + index);
    }

    value_type &operator[](size_type index)
    {
        assert(index < _size);

        return *(_buffer + index);
    }

    const value_type &operator[](size_type index) const
    {
        assert(index < _size);

        return *(_buffer + index);
    }

    size_type get_size() const
    {
        return _size;
    }

    size_type size() const
    {
        return _size;
    }

    void print(void) const
    {
        std::cout << _size << " [ ";
        for (size_type i = 0; i < _size; ++i)
            std::cout << _buffer[i] << " ";
        std::cout << "]" << std::endl;
    }

    void swap(dbuffer &other)
    {
        std::swap(this->_size, other._size);
        std::swap(this->_buffer, other._buffer);
    }

private:
    size_type _size;
    value_type *_buffer;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const dbuffer<T> &d)
{
    os << d.size() << " Elements:" << std::endl;
    for (typename dbuffer<T>::size_type i = 0; i < d.size(); ++i)
        os << d[i] << " ";
    os << std::endl;
    return os;
}

#endif