#ifndef STACK_H
#define STACK_H

struct Stack;

typedef struct Stack Stack;

Stack *createStack();
void destroyStack(Stack *stack);
int stackIsEmpty(Stack *stack);
unsigned long long getStackSize(Stack *stack);
int getTopOfStack(Stack *stack);
void popFromStack(Stack *stack);
void pushIntoStack(Stack *stack, int x);

#endif