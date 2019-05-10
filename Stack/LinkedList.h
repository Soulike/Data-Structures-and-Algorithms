#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node // 节点类型
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct LinkedList // 链表类型
{
    Node *head;                // 头节点
    Node *rear;                // 尾节点
    unsigned long long length; // 当前链表长度
};

typedef struct LinkedList LinkedList;

Node *createNode(int data);

LinkedList *create();           // 创建链表
void destroy(LinkedList *list); // 销毁链表

void insert(LinkedList *list, Node *nodeBefore, Node *newNode); // 插入新节点，如果 nodeBofore 是 NULL，插入到最前面
void delete(LinkedList *list, Node *node);        // 删除指定节点
void replace(LinkedList *list, Node *oldNode, Node *newNode);   // 把指定旧节点替换为新节点
Node *get(LinkedList *list, unsigned long long index);          // 获取第 index 个节点，如果超出长度返回 NULL

#endif