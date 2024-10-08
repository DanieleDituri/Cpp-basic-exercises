#ifndef DBUFFER_H
#define DBUFFER_H

namespace dbuffer
{
    struct dynamic_buffer
    {
        unsigned int size;
        int *buffer;
    };

    void print(const dynamic_buffer &db);

    void init(dynamic_buffer &db);

    void allocate(dynamic_buffer &db, unsigned int size = 10);

    void deallocate(dynamic_buffer &db);

    void set (dynamic_buffer &db, int value);

    void copy(const dynamic_buffer &src, dynamic_buffer &dst);
}

#endif