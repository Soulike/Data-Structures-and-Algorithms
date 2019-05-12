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

int queueIsEmpty(Queue *queue)
{
    return getLengthOfLinkedList(queue->list) == 0;
}

unsigned long long getSizeOfQueue(Queue *queue)
{
    return getLengthOfLinkedList(queue->list);
}

dataTypeInQueue getFrontOfQueue(Queue *queue)
{
    return getDataOfNode(getHeadOfLinkedList(queue->list));
}

dataTypeInQueue getBackOfQueue(Queue *queue)
{
    return getDataOfNode(getRearOfLinkedList(queue->list));
}

void popFromQueue(Queue *queue)
{
    deleteFromLinkedList(queue->list, getHeadOfLinkedList(queue->list));
}

void pushIntoQueue(Queue *queue, dataTypeInQueue x)
{
    insertIntoLinkedList(queue->list, getRearOfLinkedList(queue->list), createNode(x));
}