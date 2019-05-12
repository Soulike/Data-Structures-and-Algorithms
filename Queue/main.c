#include <stdio.h>
#include "Queue.h"

int main()
{
    Queue *queue = createQueue();
    for (int i = 0; i < 10; i++)
    {
        pushIntoQueue(queue, i);
    }
    while (!queueIsEmpty(queue))
    {
        printf("%d, %d\n", getFrontOfQueue(queue), getBackOfQueue(queue));
        popFromQueue(queue);
    }
}