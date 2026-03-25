#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// this will create a new tree node with the given character
// the parameters are:
// - value: this is the character value to be stored in the new node
// it will return the pointer to the newly created node
// then it will exit the program if memory allocation fails

static TreeNode *createNode(char value) 
{
	TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
	
	if (newNode == NULL) 
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

// this inserts a character into the binary search tree (BST)
// if the value already exists, it is not inserted again

TreeNode* insertNode(TreeNode* root, char value)
{
	if (root == NULL)
	{
		return createNode(value);
	}

	if (value < root->data)
	{
	root->left = insertNode(root->left, value);
	}
	else if (value > root->data)
	{
		root->right = insertNode(root->right, value);
	}
	return root;
}

// this will search for a character in the binary search tree (BST)

TreeNode *searchNode(TreeNode *root, char value) 
{
	if (root == NULL || root->data == value) 
	{
		return root;
	}
	
	if (value < root->data) 
	{
		return searchNode(root->left, value);
	}
	else 
	{
		return searchNode(root->right, value);
	}
}

// this counts all the nodes in the binary search tree (BST) recurisvely

int countNodes(TreeNode *root) 
{
	if (root == NULL) 
	{
		return 0;
	}
	
	return 1 + countNodes(root->left) + countNodes(root->right);
}

// this returns the height of the binary search tree (BST) recursively

int treeHeight(TreeNode *root) 
{
	int leftHeight, rightHeight;

	if (root == NULL) 
	{
		return -1;
	}

	leftHeight = treeHeight(root->left);
	rightHeight = treeHeight(root->right);

	if (leftHeight > rightHeight) 
	{
		return leftHeight + 1;
	} 
	else 
	{
		return rightHeight + 1;
	}
}

// this will print the binary search tree (BST) in an inorder traversal

void printInOrder(TreeNode *root) 
{
	if (root != NULL) 
	{
		printInOrder(root->left);
		printf("%c ", root->data);
		printInOrder(root->right);
	}
}

// this will free all nodes in the tree using post order traversal

void freeTree(TreeNode *root) 
{
	if (root != NULL) 
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}