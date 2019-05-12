#ifndef ABSTRACT_STACK_H
#define ABSTRACT_STACK_H
#include <cstddef>

template <class T>
class AbstractStack
{
public:
    virtual ~AbstractStack() {}
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual T top() const = 0;
    virtual void pop() = 0;
    virtual void push(T value) = 0;
    virtual AbstractStack<T> *clone() const = 0;
};

#endif