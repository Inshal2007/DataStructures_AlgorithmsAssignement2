#pragma once
#ifndef BST_H
#define BST_H

// This is a header file for the binary search tree, I have made a shortform named "BST" for it
// This willbe used to store lower case characters

// in this current file it will contain
// - the tree node structure
// - the function prototypes for the binary search tree (BST) operations

typedef struct TreeNode 
{
    char data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

// this will insert characters into the binary search tree (BST)
// duplicated characters will not be inserted
// the parameters are:
// - root: this is the pointer to the root of the tree
// - value: this is the character value to be inserted into the tree

// it will return to the pointer to the root of the tree after the updated tree

TreeNode *insertNode(TreeNode *root, char value);

// this will search for characters in the binary search tree (BST)
// the parameters are:
// - root: this is the pointer to the root of the tree
// - value: this is the character value to be searched in the tree

// it will return the pointer to the node containing the value if found, otherwise it'll be NULL

TreeNode *searchNode(TreeNode *root, char value);

// this will count all the number of nodes in the binary search tree (BST)
// the parameters are:
// - root: this is the pointer to the root of the tree

// it will return the total number of nodes in the tree after counting

int countNodes(TreeNode *root);

// this will determine the height of the binary search tree (BST)
// the definition used here is a empty tree of height -1, a tree with only one node has height 0, and so on
// the parameters are:
// - root: this is the pointer to the root of the tree

// it will return the height of the tree

int getHeight(TreeNode *root);

// this will print the binary search tree (BST) in an inorder traversal
// the parameters are:
// - root: this is the pointer to the root of the tree

void inorderTraversal(TreeNode *root);

// this will free the memory allocated for the binary search tree (BST)
// the parameters are:
// - root: this is the pointer to the root of the tree

void freeTree(TreeNode *root);
#endif