#include "LinkedList.h"
#include "Queue.h"
#include <stdlib.h>

struct _Queue
{
    LinkedList *list;
};

Queue *createQueue()
{
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->list = createLinkedList();
    return newQueue;
}

void destroyQueue(Queue *queue)
{
    destroyLinkedList(queue->list);
    free(queue);
}

int empty(Queue *queue)
{
    return getLengthOfLinkedList(queue->list) == 0;
}

unsigned long long size(Queue *queue)
{
    return getLengthOfLinkedList(queue->list);
}

int front(Queue *queue)
{
    return getDataOfNode(getHeadOfLinkedList(queue->list));
}

int back(Queue *queue)
{
    return getDataOfNode(getRearOfLinkedList(queue->list));
}

void pop(Queue *queue)
{
    deleteFromLinkedList(queue->list, getHeadOfLinkedList(queue->list));
}

void push(Queue *queue, int x)
{
    insertIntoLinkedList(queue->list, getRearOfLinkedList(queue->list), createNode(x));
}