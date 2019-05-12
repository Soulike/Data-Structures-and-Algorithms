#ifndef QUEUE_H
#define QUEUE_H
#include "BinaryTree.h"

struct _Queue;

typedef struct _Queue Queue;
typedef TreeNode *dataTypeInQueue; // 所容纳数据类型，根据需要修改

Queue *createQueue();
void destroyQueue(Queue *);
int queueIsEmpty(Queue *);
unsigned long long getSizeOfQueue(Queue *);
dataTypeInQueue getFrontOfQueue(Queue *);
dataTypeInQueue getBackOfQueue(Queue *);
void popFromQueue(Queue *);
void pushIntoQueue(Queue *, dataTypeInQueue x);

#endif