#include "BinaryTree.h"
#include<stdio.h>

int main()
{
    TreeNode *treeNodeArray[8];
    for (int i = 0; i < 8; i++)
    {
        treeNodeArray[i] = createTreeNode(i + 1);
    }

    setLeftTreeNode(treeNodeArray[0], treeNodeArray[1]);
    setRightTreeNode(treeNodeArray[0], treeNodeArray[2]);
    setLeftTreeNode(treeNodeArray[1], treeNodeArray[3]);
    setRightTreeNode(treeNodeArray[1], treeNodeArray[4]);
    setRightTreeNode(treeNodeArray[2], treeNodeArray[5]);
    setLeftTreeNode(treeNodeArray[3], treeNodeArray[6]);
    setLeftTreeNode(treeNodeArray[5], treeNodeArray[7]);

    BinaryTree *binaryTree = createBinaryTree();
    setRootTreeNode(binaryTree, treeNodeArray[0]);

    BinaryTree *binaryTreeCopy = cloneBinaryTree(binaryTree);

    //levelOrderPrint(binaryTree);
    //frontOrderPrint(binaryTree);
    //midOrderPrint(binaryTree);
    backOrderPrint(binaryTree);

    destroyBinaryTree(binaryTree);
    destroyBinaryTree(binaryTreeCopy);
}