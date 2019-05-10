#include "Array.h"
#include <stdio.h>

int main()
{
    Array *array = createArray(0);
    for (int i = 9; i >= 0; i--)
    {
        insertIntoArray(array, 0, i);
    }
    for (int i = 20; i < 100; i++)
    {
        insertIntoArray(array, getLengthOfArray(array), i);
    }
    for (int i = 19; i >= 10; i--)
    {
        insertIntoArray(array, 10, i);
    }
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", getFromArray(array, i));
    }
    destroyArray(array);
}