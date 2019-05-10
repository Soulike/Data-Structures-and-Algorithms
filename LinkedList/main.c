#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>

int main()
{
    LinkedList *list = create();
    for (int i = 9; i >= 0; i--)
    {
        Node *newNode = createNode(i);
        insert(list, NULL, newNode);
    }
    for (int i = 20; i < 30; i++)
    {
        Node *newNode = createNode(i);
        insert(list, getRear(list), newNode);
    }
    Node *NodeWith9 = get(list, 9);
    for (int i = 19; i >= 10; i--)
    {
        Node *newNode = createNode(i);
        insert(list, NodeWith9, newNode);
    }
    destroy(list);
}