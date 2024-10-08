#ifndef DBUFFER_H
#define DBUFFER_H

#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <cstddef>

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

    class const_iterator; // forward declaration

    class iterator
    {
        //
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;

        iterator() : _ptr(nullptr) {}

        iterator(const iterator &other) : _ptr(other._ptr) {}

        iterator &operator=(const iterator &other)
        {
            _ptr = other._ptr;
            return *this;
        }

        ~iterator() {}

        // Ritorna il dato riferito dall'iteratore (dereferenziamento)
        reference operator*() const
        {
            return *_ptr;
        }

        // Ritorna il puntatore al dato riferito dall'iteratore
        pointer operator->() const
        {
            return _ptr;
        }

        // Operatore di iterazione post-incremento
        iterator operator++(int)
        {
            iterator tmp(*this);
            _ptr++;
            return tmp;
        }

        // Operatore di iterazione pre-incremento
        iterator &operator++()
        {
            _ptr++;
            return *this;
        }

        // Uguaglianza
        bool operator==(const iterator &other) const
        {
            return (_ptr == other._ptr);
        }

        // Diversita'
        bool operator!=(const iterator &other) const
        {
            return (_ptr != other._ptr); // !(*this == other);
        }

        // Solo se serve anche const_iterator aggiungere le seguenti definizioni
        friend class const_iterator;

        // Uguaglianza
        bool operator==(const const_iterator &other) const
        {
            return (_ptr == other._ptr);
        }

        // Diversita'
        bool operator!=(const const_iterator &other) const
        {
            return (_ptr != other._ptr);
        }

        // Solo se serve anche const_iterator aggiungere le precedenti definizioni

    private:
        // Dati membro

        // La classe container deve essere messa friend dell'iteratore per poter
        // usare il costruttore di inizializzazione.
        friend class dbuffer;

        // Costruttore privato di inizializzazione usato dalla classe container
        // tipicamente nei metodi begin e end
        iterator(T *ptr)
        {
            _ptr = ptr;
        }

        T *_ptr

    };

    // Ritorna l'iteratore all'inizio della sequenza dati
    iterator begin()
    {
        return iterator(_buffer);
    }

    // Ritorna l'iteratore alla fine della sequenza dati
    iterator end()
    {
        return iterator(_buffer + _size);
    }

    class const_iterator
    {
        //
    public:
        typedef std::forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;

        const_iterator() : _ptr(nullptr) {}

        const_iterator(const const_iterator &other) : _ptr(other._ptr) {}

        const_iterator &operator=(const const_iterator &other)
        {
            _ptr = other._ptr;
            return *this;
        }

        ~const_iterator() {}

        // Ritorna il dato riferito dall'iteratore (dereferenziamento)
        reference operator*() const
        {
            return *_ptr;
        }

        // Ritorna il puntatore al dato riferito dall'iteratore
        pointer operator->() const
        {
            return _ptr;
        }

        // Operatore di iterazione post-incremento
        const_iterator operator++(int)
        {
            const_iterator tmp(*this);
            _ptr++;
            return tmp;
        }

        // Operatore di iterazione pre-incremento
        const_iterator &operator++()
        {
            _ptr++;
            return *this;
        }

        // Uguaglianza
        bool operator==(const const_iterator &other) const
        {
            return (_ptr == other._ptr);
        }

        // Diversita'
        bool operator!=(const const_iterator &other) const
        {
            return (_ptr != other._ptr);
        }

        // Solo se serve anche iterator aggiungere le seguenti definizioni

        friend class iterator;

        // Uguaglianza
        bool operator==(const iterator &other) const
        {
            return (_ptr == other._ptr);
        }

        // Diversita'
        bool operator!=(const iterator &other) const
        {
            return (_ptr != other._ptr);
        }

        // Costruttore di conversione iterator -> const_iterator
        const_iterator(const iterator &other)
        {
            _ptr = other._ptr;
        }

        // Assegnamento di un iterator ad un const_iterator
        const_iterator &operator=(const iterator &other)
        {
            _ptr = other._ptr;
            return *this;
        }

        // Solo se serve anche iterator aggiungere le precedenti definizioni

    private:
        // Dati membro

        // La classe container deve essere messa friend dell'iteratore per poter
        // usare il costruttore di inizializzazione.
        friend class dbuffer; // !!! Da cambiare il nome!

        // Costruttore privato di inizializzazione usato dalla classe container
        // tipicamente nei metodi begin e end
        const_iterator(const T *ptr)
        {
            _ptr = ptr;
        }

        const T *_ptr;

        // !!! Eventuali altri metodi privati

    }; // classe const_iterator

    // Ritorna l'iteratore all'inizio della sequenza dati
    const_iterator begin() const
    {
        return const_iterator(_buffer);
    }

    // Ritorna l'iteratore alla fine della sequenza dati
    const_iterator end() const
    {
        return const_iterator(_buffer + _size);
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