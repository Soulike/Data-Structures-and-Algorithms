#include "BinaryTree.h"
#include<stdio.h>

int main()
{
    TreeNode *treeNodeArray[7];
    for (int i = 0; i < 7; i++)
    {
        treeNodeArray[i] = createTreeNode(i + 1);
    }

    setLeftTreeNode(treeNodeArray[0], treeNodeArray[1]);
    setRightTreeNode(treeNodeArray[0], treeNodeArray[2]);
    setLeftTreeNode(treeNodeArray[1], treeNodeArray[3]);
    setRightTreeNode(treeNodeArray[1], treeNodeArray[4]);
    setRightTreeNode(treeNodeArray[2], treeNodeArray[5]);
    setLeftTreeNode(treeNodeArray[3], treeNodeArray[6]);
    
    BinaryTree *binaryTree = createBinaryTree();
    setRootTreeNode(binaryTree, treeNodeArray[0]);
    printf("%lld", height(binaryTree));

    BinaryTree *binaryTreeCopy = cloneBinaryTree(binaryTree);

    destroyBinaryTree(binaryTree);
    destroyBinaryTree(binaryTreeCopy);
}