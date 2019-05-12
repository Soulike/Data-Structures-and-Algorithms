#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef int dataTypeInTreeNode;

struct TreeNode;
typedef struct TreeNode TreeNode;

TreeNode *createTreeNode(dataTypeInTreeNode data);
TreeNode *getLeftTreeNode(TreeNode *treeNode);
TreeNode *getRightTreeNode(TreeNode *treeNode);
void setLeftTreeNode(TreeNode *treeNode, TreeNode *leftTreeNode);
void setRightTreeNode(TreeNode *treeNode, TreeNode *rightTreeNode);
dataTypeInTreeNode getDataOfTreeNode(TreeNode *treeNode);
void setDataOfTreeNode(TreeNode *treeNode, dataTypeInTreeNode data);

struct BinaryTree;
typedef struct BinaryTree BinaryTree;

BinaryTree *createBinaryTree();
void destroyBinaryTree(BinaryTree *binaryTree);
int empty(BinaryTree *binaryTree);
unsigned long long height(BinaryTree *binaryTree);
// 复制已有的二叉树，复制所有节点
BinaryTree *cloneBinaryTree(BinaryTree *binaryTree);
// 根据已有的根节点建立一个二叉树，不进行复制
BinaryTree *createBinaryTreeByRootTreeNode(TreeNode *treeNode);
TreeNode *getRootTreeNode(BinaryTree *binaryTree);
void setRootTreeNode(BinaryTree *binaryTree,TreeNode *treeNode);

// 层次遍历输出 data
void levelOrderPrint(BinaryTree *binaryTree);

// 前序遍历输出 data
void frontOrderPrint(BinaryTree *binaryTree);

// 中序遍历输出 data
void midOrderPrint(BinaryTree *binaryTree);

// 后序遍历输出 data
void backOrderPrint(BinaryTree *binaryTree);

#endif