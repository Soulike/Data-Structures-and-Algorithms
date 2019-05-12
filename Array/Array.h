#ifndef ARRAY_H
#define ARRAY_H
#include "LinearList.h"
#include <cstring>

template <class T>
class Array : public LinearList<T>
{
private:
    T *container;
    size_t _capacity; // 目前最大容量
    size_t _size;     // 目前已用容量

    void expand()
    {
        T *newContainer = new T[2 * this->_capacity];
        memcpy(newContainer, this->container, this->_size * sizeof(T));
        delete[] this->container;
        this->container = newContainer;
        this->_capacity *= 2;
    }

public:
    Array(size_t initialCapacity = 10)
    {
        this->container = new T[initialCapacity];
        this->_capacity = initialCapacity;
        this->_size = 0;
    }

    ~Array()
    {
        delete[] this->container;
    }

    bool empty() const
    {
        return this->_size == 0;
    }

    size_t capacity() const
    {
        return this->_capacity;
    }

    size_t size() const
    {
        return this->_size;
    }

    T get(size_t index) const
    {
        return this->container[index];
    }

    void set(size_t index, T value)
    {
        this->container[index] = value;
    }

    void insert(size_t index, T value)
    {
        if (this->_size == this->_capacity)
        {
            this->expand();
        }
        memmove(this->container + index + 1, this->container + index, (this->_size - index) * sizeof(T));
        this->container[index] = value;
        this->_size++;
    }

    void erase(size_t index)
    {
        memmove(this->container + index, this->container + index + 1, (this->_size - index - 1) * sizeof(T));
        this->_size--;
    }

    Array<T> *clone() const
    {
        Array<T> *newArray = new Array<T>(this->_capacity);
        memcpy(newArray->container, this->container, this->_size * sizeof(T));
        newArray->_size = this->_size;
        return newArray;
    }
};

#endif