#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct _Node;
struct _LinkedList;
typedef struct _Node Node;
typedef struct _LinkedList LinkedList;

Node *createNode(int data);
int getData(Node *node);
void setData(Node *node, int data);
Node *getNext(Node *node);

LinkedList *create();           // 创建链表
void destroy(LinkedList *list); // 销毁链表
Node *getHead(LinkedList *list);
Node *getRear(LinkedList *list);
unsigned long long getLength(LinkedList *list);
void insert(LinkedList *list, Node *nodeBefore, Node *newNode); // 插入新节点，如果 nodeBofore 是 NULL，插入到最前面
void delete(LinkedList *list, Node *node);        // 删除指定节点
void replace(LinkedList *list, Node *oldNode, Node *newNode);   // 把指定旧节点替换为新节点
Node *get(LinkedList *list, unsigned long long index);          // 获取第 index 个节点，如果超出长度返回 NULL

#endif