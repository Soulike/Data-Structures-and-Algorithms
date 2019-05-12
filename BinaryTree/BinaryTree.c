#include "BinaryTree.h"
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
#include <stdio.h>

struct TreeNode
{
    TreeNode *leftTreeNode;
    TreeNode *rightTreeNode;
    dataTypeInTreeNode data;
};

TreeNode *createTreeNode(dataTypeInTreeNode data)
{
    TreeNode *newTreeNode = (TreeNode *)malloc(sizeof(TreeNode));
    newTreeNode->data = data;
    newTreeNode->leftTreeNode = NULL;
    newTreeNode->rightTreeNode = NULL;
    return newTreeNode;
}

TreeNode *getLeftTreeNode(TreeNode *treeNode)
{
    return treeNode->leftTreeNode;
}

TreeNode *getRightTreeNode(TreeNode *treeNode)
{
    return treeNode->rightTreeNode;
}

void setLeftTreeNode(TreeNode *treeNode, TreeNode *leftTreeNode)
{
    treeNode->leftTreeNode = leftTreeNode;
}

void setRightTreeNode(TreeNode *treeNode, TreeNode *rightTreeNode)
{
    treeNode->rightTreeNode = rightTreeNode;
}

dataTypeInTreeNode getDataOfTreeNode(TreeNode *treeNode)
{
    return treeNode->data;
}

void setDataOfTreeNode(TreeNode *treeNode, dataTypeInTreeNode data)
{
    treeNode->data = data;
}

struct BinaryTree
{
    TreeNode *rootTreeNode;
};

BinaryTree *createBinaryTree()
{
    BinaryTree *binaryTree = (BinaryTree *)malloc(sizeof(BinaryTree));
    binaryTree->rootTreeNode = NULL;
    return binaryTree;
}

// 递归方式销毁整个树
static void destroyBinaryTreeByRootTreeNode(TreeNode *rootTreeNode)
{
    TreeNode *leftTreeNode = rootTreeNode->leftTreeNode;
    TreeNode *rightTreeNode = rootTreeNode->rightTreeNode;
    if (leftTreeNode != NULL)
    {
        destroyBinaryTreeByRootTreeNode(leftTreeNode);
    }
    if (rightTreeNode != NULL)
    {
        destroyBinaryTreeByRootTreeNode(rightTreeNode);
    }
    free(rootTreeNode);
}

void destroyBinaryTree(BinaryTree *binaryTree)
{
    if (binaryTree->rootTreeNode != NULL)
    {
        destroyBinaryTreeByRootTreeNode(binaryTree->rootTreeNode);
    }
    free(binaryTree);
}

int empty(BinaryTree *binaryTree)
{
    return binaryTree->rootTreeNode == NULL;
}

static unsigned long long heightRecursive(TreeNode *rootTreeNode)
{
    if (rootTreeNode == NULL)
    {
        return 0;
    }
    else
    {
        unsigned long long leftTreeHeight = heightRecursive(rootTreeNode->leftTreeNode);
        unsigned long long rightTreeHeight = heightRecursive(rootTreeNode->rightTreeNode);
        unsigned long long maxSubTreeHeight = leftTreeHeight > rightTreeHeight ? leftTreeHeight : rightTreeHeight;
        return maxSubTreeHeight + 1;
    }
}

unsigned long long height(BinaryTree *binaryTree)
{
    return heightRecursive(binaryTree->rootTreeNode);
}

// 递归方式克隆整个树
static TreeNode *cloneBinaryTreeByRootTreeNode(TreeNode *rootTreeNode)
{
    TreeNode *leftTreeNode = rootTreeNode->leftTreeNode;
    TreeNode *rightTreeNode = rootTreeNode->rightTreeNode;
    TreeNode *newRootTreeNode = createTreeNode(rootTreeNode->data);
    if (leftTreeNode != NULL)
    {
        newRootTreeNode->leftTreeNode = cloneBinaryTreeByRootTreeNode(leftTreeNode);
    }
    if (rightTreeNode != NULL)
    {
        newRootTreeNode->rightTreeNode = cloneBinaryTreeByRootTreeNode(rightTreeNode);
    }
    return newRootTreeNode;
}

BinaryTree *cloneBinaryTree(BinaryTree *binaryTree)
{
    TreeNode *newRootTreeNode = NULL;
    if (binaryTree->rootTreeNode != NULL)
    {
        newRootTreeNode = cloneBinaryTreeByRootTreeNode(binaryTree->rootTreeNode);
    }
    return createBinaryTreeByRootTreeNode(newRootTreeNode);
}

BinaryTree *createBinaryTreeByRootTreeNode(TreeNode *treeNode)
{
    BinaryTree *newBinaryTree = createBinaryTree();
    newBinaryTree->rootTreeNode = treeNode;
    return newBinaryTree;
}

TreeNode *getRootTreeNode(BinaryTree *binaryTree)
{
    return binaryTree->rootTreeNode;
}

void setRootTreeNode(BinaryTree *binaryTree, TreeNode *treeNode)
{
    binaryTree->rootTreeNode = treeNode;
}

void levelOrderPrint(BinaryTree *binaryTree)
{
    Queue *queue = createQueue();
    pushIntoQueue(queue, binaryTree->rootTreeNode);
    TreeNode *currentTreeNode = NULL;
    while (!queueIsEmpty(queue))
    {
        currentTreeNode = getFrontOfQueue(queue);
        printf("%d", currentTreeNode->data); // 注意，只适用于 int
        popFromQueue(queue);
        if (currentTreeNode->leftTreeNode != NULL)
        {
            pushIntoQueue(queue, currentTreeNode->leftTreeNode);
        }
        if (currentTreeNode->rightTreeNode != NULL)
        {
            pushIntoQueue(queue, currentTreeNode->rightTreeNode);
        }
    }
    destroyQueue(queue);
}

// 前序遍历输出 data
void frontOrderPrint(BinaryTree *binaryTree)
{
    Stack *stack = createStack();
    TreeNode *currentTreeNode = binaryTree->rootTreeNode;
    while (currentTreeNode != NULL || !stackIsEmpty(stack))
    {
        if (currentTreeNode != NULL)
        {
            printf("%d", currentTreeNode->data);
            pushIntoStack(stack, currentTreeNode);
            currentTreeNode = currentTreeNode->leftTreeNode;
        }
        else
        {
            currentTreeNode = getTopOfStack(stack);
            popFromStack(stack);
            currentTreeNode = currentTreeNode->rightTreeNode;
        }
    }
    destroyStack(stack);
}

// 中序遍历输出 data
void midOrderPrint(BinaryTree *binaryTree)
{
    Stack *stack = createStack();
    TreeNode *currentTreeNode = binaryTree->rootTreeNode;
    while (currentTreeNode != NULL || !stackIsEmpty(stack))
    {
        if (currentTreeNode != NULL)
        {
            pushIntoStack(stack, currentTreeNode);
            currentTreeNode = currentTreeNode->leftTreeNode;
        }
        else
        {
            currentTreeNode = getTopOfStack(stack);
            printf("%d", currentTreeNode->data);
            currentTreeNode = currentTreeNode->rightTreeNode;
            popFromStack(stack);
        }
    }
    destroyStack(stack);
}

// 后序遍历输出 data
void backOrderPrint(BinaryTree *binaryTree)
{
    Stack *stack = createStack();
    TreeNode *currentTreeNode = binaryTree->rootTreeNode;
    TreeNode *lastVisitNode = NULL;
    while (currentTreeNode != NULL || !stackIsEmpty(stack))
    {
        if (currentTreeNode != NULL)
        {
            pushIntoStack(stack, currentTreeNode);
            currentTreeNode = currentTreeNode->leftTreeNode;
        }
        else
        {
            currentTreeNode = getTopOfStack(stack);
            if (currentTreeNode->rightTreeNode == NULL || currentTreeNode->rightTreeNode == lastVisitNode)
            {
                printf("%d", currentTreeNode->data);
                lastVisitNode = currentTreeNode;
                popFromStack(stack);
                currentTreeNode = NULL;
            }
            else
            {
                currentTreeNode = currentTreeNode->rightTreeNode;
            }
        }
    }
    destroyStack(stack);
}