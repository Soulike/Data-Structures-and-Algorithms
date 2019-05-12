#ifndef STACK_H
#define STACK_H

struct Stack;

typedef struct Stack Stack;

typedef int dataTypeInStack;

Stack *createStack();
void destroyStack(Stack *stack);
int stackIsEmpty(Stack *stack);
unsigned long long getStackSize(Stack *stack);
dataTypeInStack getTopOfStack(Stack *stack);
void popFromStack(Stack *stack);
void pushIntoStack(Stack *stack, dataTypeInStack x);

#endif