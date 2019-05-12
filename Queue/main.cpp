#include <cstdio>
#include "Queue.h"

int main()
{
    Queue<int> *queue = new Queue<int>();
    for (int i = 0; i < 10; i++)
    {
        queue->push(i);
    }
    while (!queue->empty())
    {
        printf("%d, %d\n", queue->front(), queue->back());
        queue->pop();
    }
}