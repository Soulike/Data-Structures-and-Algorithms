#include "Stack.h"
#include<stdlib.h>
#include "LinkedList.h"

struct Stack
{
    LinkedList *list;
};

Stack *createStack()
{
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->list = create();
    return stack;
}

void destroyStack(Stack *stack)
{
    destroy(stack->list);
    free(stack);
}

int empty(Stack *stack)
{
    return getLength(stack->list) == 0;
}

unsigned long long size(Stack *stack)
{
    return getLength(stack->list);
}

int top(Stack *stack)
{
    return getData(getHead(stack->list));
}

void pop(Stack *stack)
{
    delete (stack->list, getHead(stack->list));
}

void push(Stack *stack, int x)
{
    Node *newNode = createNode(x);
    insert(stack->list, NULL, newNode);
}