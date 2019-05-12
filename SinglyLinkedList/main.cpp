#include "SinglyLinkedList.h"
#include <stdio.h>

int main()
{
    LinearList<int> *linearList = new SinglyLinkedList<int>();
    for (int i = 9; i >= 0; i--)
    {
        linearList->insert(0, i);
    }
    for (int i = 20; i < 100; i++)
    {
        linearList->insert(linearList->size(), i);
    }
    for (int i = 19; i >= 10; i--)
    {
        linearList->insert(10, i);
    }
    LinearList<int> *linearList2 = linearList->clone();
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", linearList2->get(i));
    }
    delete linearList;
    delete linearList2;
}