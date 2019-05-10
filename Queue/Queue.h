#ifndef QUEUE_H
#define QUEUE_H

struct _Queue;

typedef struct _Queue Queue;

Queue *createQueue();
void destroyQueue(Queue *);
int empty(Queue *);
unsigned long long size(Queue *);
int front(Queue *);
int back(Queue *);
void pop(Queue *);
void push(Queue *, int);

#endif