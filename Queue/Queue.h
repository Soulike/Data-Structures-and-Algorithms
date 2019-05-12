#ifndef QUEUE_H
#define QUEUE_H
#include "AbstractQueue.h"
#include "SinglyLinkedList.h"

template <class T>
class Queue
{
private:
    LinearList<T> *container;

public:
    Queue()
    {
        this->container = new SinglyLinkedList<T>();
    }

    ~Queue()
    {
        delete this->container;
    }

    bool empty() const
    {
        return this->container->empty();
    }

    size_t size() const
    {
        return this->container->size();
    }

    T front() const
    {
        return this->container->get(0);
    }

    T back() const
    {
        return this->container->get(this->container->size() - 1);
    }

    void pop()
    {
        this->container->erase(0);
    }

    void push(T value)
    {
        this->container->insert(this->container->size(), value);
    }
    Queue<T> *clone() const
    {
        Queue<T> *newQueue = new Queue<T>();
        newQueue->container = this->container->clone();
        return newQueue;
    }
};

#endif