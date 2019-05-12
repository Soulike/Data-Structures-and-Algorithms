#include "Stack.h"
#include <cstdio>

int main()
{
    Stack<int> *stack = new Stack<int>();
    for (int i = 0; i < 10; i++)
    {
        stack->push(i);
    }
    Stack<int> *stack2 = stack->clone();
    for (int i = 0; i < 10; i++)
    {
        printf("%d", stack2->top());
        stack2->pop();
    }
    delete stack;
    delete stack2;
}