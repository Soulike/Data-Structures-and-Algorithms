#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>

int main()
{
    LinkedList *list = createLinkedList();
    for (int i = 9; i >= 0; i--)
    {
        Node *newNode = createNode(i);
        insertIntoLinkedList(list, NULL, newNode);
    }
    for (int i = 20; i < 30; i++)
    {
        Node *newNode = createNode(i);
        insertIntoLinkedList(list, getRearOfLinkedList(list), newNode);
    }
    Node *NodeWith9 = getFromLinkedList(list, 9);
    for (int i = 19; i >= 10; i--)
    {
        Node *newNode = createNode(i);
        insertIntoLinkedList(list, NodeWith9, newNode);
    }
    destroyLinkedList(list);
}