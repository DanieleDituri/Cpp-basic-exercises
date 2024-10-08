#include <iostream>

#include "dbuffer.h"

namespace dbuffer
{
    void print(const dynamic_buffer &db)
    {
        std::cout << "Buffer size: " << db.size << std::endl;
        for (unsigned int i = 0; i < db.size; i++)
        {
            std::cout << db.buffer[i] << " ";
        }
        std::cout << std::endl;
    }

    void init(dynamic_buffer &db)
    {
        db.size = 0;
        db.buffer = nullptr;
    }

    void allocate(dynamic_buffer &db, unsigned int size)
    {
        int *tmp = new int[size];

        if (db.buffer != nullptr)
        {
            delete[] db.buffer;
            init(db);
        }

        db.buffer = tmp;
        db.size = size;
        set(db, 0);
    }

    void deallocate(dynamic_buffer &db)
    {
        delete[] db.buffer;
        init(db);
    }

    void set(dynamic_buffer &db, int value)
    {
        for (unsigned int i = 0; i < db.size; i++)
        {
            db.buffer[i] = value;
        }
    }

    void copy(const dynamic_buffer &src, dynamic_buffer &dst)
    {
        allocate(dst, src.size);
        for (unsigned int i = 0; i < src.size; i++)
        {
            dst.buffer[i] = src.buffer[i];
        }
    }
}