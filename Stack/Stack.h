#ifndef STACK_H
#define STACK_H
#include "AbstractStack.h"
#include "SinglyLinkedList.h"

template <class T>
class Stack : public AbstractStack<T>
{
private:
    LinearList<T>* container;

public:
    Stack()
    {
        this->container = new SinglyLinkedList<T>();
    }

    ~Stack()
    {
        delete this->container;
    }

    bool empty() const
    {
        return container->empty();
    }

    size_t size() const
    {
        return container->size();
    }

    T top() const
    {
        return this->container->get(0);
    }

    void pop()
    {
        this->container->erase(0);
    }

    void push(T value)
    {
        this->container->insert(0, value);
    }

    Stack<T> *clone() const
    {
        Stack<T> *newStack = new Stack<T>();
        newStack->container = this->container->clone();
        return newStack;
    }
};

#endif