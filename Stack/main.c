#include"Stack.h"
#include<stdio.h>

int main()
{
    Stack *stack = createStack();
    for (int i = 0; i < 10;i++)
    {
        pushIntoStack(stack, i);
    }
    for (int i = 0; i < 5;i++)
    {
        printf("%d", getTopOfStack(stack));
        popFromStack(stack);
    }
    destroyStack(stack);
}