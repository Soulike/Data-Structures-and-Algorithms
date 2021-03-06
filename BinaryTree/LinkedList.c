#include "LinkedList.h"
#include <stdlib.h>

struct _Node // 节点类型
{
    dataTypeInLinkedList data;
    struct _Node *next;
};

struct _LinkedList // 链表类型
{
    Node *head;                // 头节点
    Node *rear;                // 尾节点
    unsigned long long length; // 当前链表长度
};

Node *createNode(dataTypeInLinkedList data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

dataTypeInLinkedList getDataOfNode(Node *node)
{
    return node->data;
}

void setDataOfNode(Node *node, dataTypeInLinkedList data)
{
    node->data = data;
}

Node *getNextOfNode(Node *node)
{
    return node->next;
}

LinkedList *createLinkedList()
{
    LinkedList *newList = (LinkedList *)malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->rear = NULL;
    newList->length = 0;
    return newList;
}

void destroyLinkedList(LinkedList *list)
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

Node *getHeadOfLinkedList(LinkedList *list)
{
    return list->head;
}

Node *getRearOfLinkedList(LinkedList *list)
{
    return list->rear;
}

unsigned long long getLengthOfLinkedList(LinkedList *list)
{
    return list->length;
}

void insertIntoLinkedList(LinkedList *list, Node *nodeBefore, Node *newNode)
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

void deleteFromLinkedList(LinkedList *list, Node *node)
{
    if (node == list->head)
    {
        list->head = node->next;
        free(node);
        list->length--;
        if (list->head == NULL)
        {
            list->rear = NULL;
        }
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

void replaceFromLinkedList(LinkedList *list, Node *oldNode, Node *newNode)
{
    insertIntoLinkedList(list, oldNode, newNode);
    deleteFromLinkedList(list, oldNode);
}

Node *getFromLinkedList(LinkedList *list, unsigned long long index)
{
    Node *currentNode = list->head;
    for (unsigned long long i = 0; i < index && currentNode != NULL; i++)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}