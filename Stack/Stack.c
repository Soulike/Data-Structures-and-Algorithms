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
    stack->list = createLinkedList();
    return stack;
}

void destroyStack(Stack *stack)
{
    destroyLinkedList(stack->list);
    free(stack);
}

int empty(Stack *stack)
{
    return getLengthOfLinkedList(stack->list) == 0;
}

unsigned long long size(Stack *stack)
{
    return getLengthOfLinkedList(stack->list);
}

int top(Stack *stack)
{
    return getDataOfNode(getHeadOfLinkedList(stack->list));
}

void pop(Stack *stack)
{
    deleteFromLinkedList(stack->list, getHeadOfLinkedList(stack->list));
}

void push(Stack *stack, int x)
{
    Node *newNode = createNode(x);
    insertIntoLinkedList(stack->list, NULL, newNode);
}