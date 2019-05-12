#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H
#include <cstddef>

template <class T>
class LinearList
{
public:
    virtual ~LinearList() {}
    virtual bool empty() const = 0;
    virtual size_t capacity() const = 0;
    virtual size_t size() const = 0;
    virtual T get(size_t index) const = 0;

    virtual void insert(size_t index, T value) = 0;
    virtual void erase(size_t index) = 0;

    virtual LinearList<T> *clone() const = 0;
};

#endif