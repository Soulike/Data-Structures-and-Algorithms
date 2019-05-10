#include <stdio.h>
#include "Queue.h"

int main()
{
    Queue *queue = createQueue();
    for (int i = 0; i < 10; i++)
    {
        push(queue, i);
    }
    while (!empty(queue))
    {
        printf("%d, %d\n", front(queue), back(queue));
        pop(queue);
    }
}