#include "BinaryTree.h"
#include <stdlib.h>

struct TreeNode
{
    TreeNode *leftTreeNode;
    TreeNode *rightTreeNode;
    int data;
};

TreeNode *createTreeNode(int data)
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

int getDataOfTreeNode(TreeNode *treeNode)
{
    return treeNode->data;
}

void setDataOfTreeNode(TreeNode *treeNode, int data)
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