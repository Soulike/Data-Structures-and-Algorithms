#include "LinkedList.h"
#include <stdlib.h>

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList *create()
{
    LinkedList *newList = (LinkedList *)malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->rear = NULL;
    newList->length = 0;
    return newList;
}

void destroy(LinkedList *list)
{
    Node *nodeBefore = list->head;
    Node *nextNode = NULL;
    while (nodeBefore != NULL)
    {
        nextNode = nodeBefore->next;
        free(nodeBefore);
        nodeBefore = nextNode;
    }
    free(list);
}

void insert(LinkedList *list, Node *nodeBefore, Node *newNode)
{
    if (nodeBefore == NULL) // 如果之前参照节点是 NULL，就插入成为 head
    {
        newNode->next = list->head;
        list->head = newNode;
    }
    else
    {
        Node *nodeAfter = nodeBefore->next;
        nodeBefore->next = newNode;
        newNode->next = nodeAfter;
    }
    if (newNode->next == NULL)
    {
        list->rear = newNode;
    }
    list->length++;
}

void delete(LinkedList *list, Node *node)
{
    if (node == list->head)
    {
        list->head = node->next;
        free(node);
        list->length--;
    }
    else
    {
        Node *nodeBefore = list->head;
        while (nodeBefore->next != node && nodeBefore->next != NULL)
        {
            nodeBefore = nodeBefore->next;
        }
        if (nodeBefore->next != NULL)
        {
            nodeBefore->next = node->next;
            free(node);
            if (nodeBefore->next == NULL)
            {
                list->rear = nodeBefore;
            }
            list->length--;
        }
    }
}

void replace(LinkedList *list, Node *oldNode, Node *newNode)
{
    insert(list, oldNode, newNode);
    delete(list, oldNode);
}

Node *get(LinkedList *list, unsigned long long index)
{
    Node *currentNode = list->head;
    for (unsigned long long i = 0; i < index && currentNode != NULL; i++)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}