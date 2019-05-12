#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct _Node;
struct _LinkedList;
typedef struct _Node Node;
typedef struct _LinkedList LinkedList;

typedef int dataTypeInLinkedList; // 所容纳数据类型，根据需要修改

Node *createNode(dataTypeInLinkedList data);
dataTypeInLinkedList getDataOfNode(Node *node);
void setDataOfNode(Node *node, dataTypeInLinkedList data);
Node *getNextOfNode(Node *node);

LinkedList *createLinkedList();           // 创建链表
void destroyLinkedList(LinkedList *list); // 销毁链表
Node *getHeadOfLinkedList(LinkedList *list);
Node *getRearOfLinkedList(LinkedList *list);
unsigned long long getLengthOfLinkedList(LinkedList *list);
void insertIntoLinkedList(LinkedList *list, Node *nodeBefore, Node *newNode); // 插入新节点，如果 nodeBofore 是 NULL，插入到最前面
void deleteFromLinkedList(LinkedList *list, Node *node);                      // 删除指定节点
void replaceFromLinkedList(LinkedList *list, Node *oldNode, Node *newNode);   // 把指定旧节点替换为新节点
Node *getFromLinkedList(LinkedList *list, unsigned long long index);          // 获取第 index 个节点，如果超出长度返回 NULL

#endif