#include "LinearList.h"

template <class T>
class SinglyLinkedList : public LinearList<T>
{
private:
    template <class U>
    class SinglyNode
    {
    private:
        U data;
        SinglyNode<U> *next;

    public:
        SinglyNode(U data)
        {
            this->data = data;
            this->next = nullptr;
        }
        ~SinglyNode() {}

        U getData() const
        {
            return this->data;
        }

        void setData(U data)
        {
            this->data = data;
        }

        SinglyNode<U> *getNext() const
        {
            return this->next;
        }

        void setNext(SinglyNode<U> *next)
        {
            this->next = next;
        }
    };

    SinglyNode<T> *head;
    size_t _size;

public:
    SinglyLinkedList()
    {
        this->head = nullptr;
        this->_size = 0;
    }
    ~SinglyLinkedList()
    {
        SinglyNode<T> *currentNode = this->head;
        SinglyNode<T> *nextNode = nullptr;
        while (currentNode != nullptr)
        {
            nextNode = currentNode->getNext();
            delete currentNode;
            currentNode = nextNode;
        }
    }

    bool empty() const
    {
        return this->head == nullptr;
    }

    size_t capacity() const
    {
        return this->size();
    }

    size_t size() const
    {
        return this->_size;
    }

    T get(size_t index) const
    {
        SinglyNode<T> *currentNode = this->head;
        for (size_t i = 0; i < index; i++)
        {
            currentNode = currentNode->getNext();
        }
        return currentNode->getData();
    }

    void insert(size_t index, T value)
    {
        SinglyNode<T> *newNode = new SinglyNode<T>(value);
        SinglyNode<T> *nextNode = this->head;
        SinglyNode<T> *prevNode = nullptr;
        if (this->head != nullptr) // 如果链表不是空的
        {
            for (size_t i = 0; i < index; i++)
            {
                prevNode = nextNode;
                nextNode = nextNode->getNext();
            }
            if (prevNode != nullptr)
            {
                prevNode->setNext(newNode);
            }
            newNode->setNext(nextNode);
        }
        if (index == 0)
        {
            this->head = newNode;
        }

        this->_size++;
    }

    void erase(size_t index)
    {
        SinglyNode<T> *currentNode = this->head;
        SinglyNode<T> *prevNode = nullptr;
        for (size_t i = 0; i < index; i++)
        {
            prevNode = currentNode;
            currentNode = currentNode->getNext();
        }
        if (prevNode != nullptr)
        {
            prevNode->setNext(currentNode->getNext());
        }
        if(index == 0)
        {
            this->head = currentNode->getNext();
        }
        delete currentNode;
        this->_size--;
    }

    SinglyLinkedList<T> *clone() const
    {
        SinglyLinkedList<T> *newList = new SinglyLinkedList<T>();
        SinglyNode<T> *currentNode = this->head;
        while (currentNode != nullptr)
        {
            newList->insert(newList->size(), currentNode->getData());
            currentNode = currentNode->getNext();
        }
        return newList;
    }
};
