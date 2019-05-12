#include "Array.h"
#include <stdio.h>

int main()
{
    Array<int> *array = new Array<int>();
    for (int i = 9; i >= 0; i--)
    {
        array->insert(0, i);
    }
    for (int i = 20; i < 100; i++)
    {
        array->insert(array->size(), i);
    }
    for (int i = 19; i >= 10; i--)
    {
        array->insert(10, i);
    }
    Array<int> *array2 = array->clone();
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", array2->get(i));
    }
    delete array;
    delete array2;
}