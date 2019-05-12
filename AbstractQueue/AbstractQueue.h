#ifndef ABSTRACT_QUEUE_H
#define ABSTRACT_QUEUE_H
#include <cstddef>

template <class T>
class AbstractQueue
{
public:
    virtual ~AbstractQueue() {}
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual void pop() = 0;
    virtual void push(T value) = 0;
    virtual AbstractQueue<T> *clone() const = 0;
};

#endif