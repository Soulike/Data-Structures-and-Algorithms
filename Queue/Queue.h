#ifndef QUEUE_H
#define QUEUE_H

struct _Queue;

typedef struct _Queue Queue;

Queue *createQueue();
void destroyQueue(Queue *);
int queueIsEmpty(Queue *);
unsigned long long getSizeOfQueue(Queue *);
int getFrontOfQueue(Queue *);
int getBackOfQueue(Queue *);
void popFromQueue(Queue *);
void pushIntoQueue(Queue *, int);

#endif