#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"

struct Stack
{
    LinkedList *list;
};

typedef struct Stack Stack;

Stack *createStack();
void destroyStack(Stack *stack);
int empty(Stack *stack);
unsigned long long size(Stack *stack);
int top(Stack *stack);
void pop(Stack *stack);
void push(Stack *stack, int x);

#endif