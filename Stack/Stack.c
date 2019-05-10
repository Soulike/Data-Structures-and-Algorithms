#include "Stack.h"
#include<stdlib.h>

Stack *createStack()
{
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->list = (LinkedList *)malloc(sizeof(LinkedList));
    return stack;
}

void destroyStack(Stack *stack)
{
    destroy(stack->list);
    free(stack);
}

int empty(Stack *stack)
{
    return stack->list->length == 0;
}

unsigned long long size(Stack *stack)
{
    return stack->list->length;
}

int top(Stack *stack)
{
    return stack->list->head->data;
}

void pop(Stack *stack)
{
    delete(stack->list, stack->list->head);
}

void push(Stack *stack, int x)
{
    Node *newNode = createNode(x);
    insert(stack->list, NULL, newNode);
}