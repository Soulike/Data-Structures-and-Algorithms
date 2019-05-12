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

int stackIsEmpty(Stack *stack)
{
    return getLengthOfLinkedList(stack->list) == 0;
}

unsigned long long getStackSize(Stack *stack)
{
    return getLengthOfLinkedList(stack->list);
}

dataTypeInStack getTopOfStack(Stack *stack)
{
    return getDataOfNode(getHeadOfLinkedList(stack->list));
}

void popFromStack(Stack *stack)
{
    deleteFromLinkedList(stack->list, getHeadOfLinkedList(stack->list));
}

void pushIntoStack(Stack *stack, dataTypeInStack x)
{
    Node *newNode = createNode(x);
    insertIntoLinkedList(stack->list, NULL, newNode);
}