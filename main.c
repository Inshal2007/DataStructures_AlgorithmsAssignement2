#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

 // this will generates a random lowercase character from 'a' to 'z'
 // this will return:
 // - A random character in the range a-z.

static char randomLowercaseChar(void)
{
    return (char)('a' + (rand() % 26));
}

int main(void)
{
    TreeNode* root = NULL;
    int numberOfChars;
    int insertedCount = 0;
    char letter;

    // this will give the seed of the random number generator using current time
   
    srand((unsigned int)time(NULL));

    // it'll generate a random number from 11 to 20 inclusive.
    
    numberOfChars = 11 + (rand() % 10);

    printf("Binary Search Tree of Characters\n");
    printf("--------------------------------\n");
    printf("Random number of characters to insert: %d\n\n", numberOfChars);

    printf("Characters generated for insertion:\n");

    
     // this will insert random lowercase letters into the tree
     // Duplicates may be generated, but the BST insert
     // function ignores duplicate values
     
    for (int i = 0; i < numberOfChars; i++)
    {
        letter = randomLowercaseChar();
        printf("%c ", letter);
        root = insertNode(root, letter);
    }

    printf("\n\n");

    
     // this will print the tree contents in sorted alphabetical order
     // it will be inorder traversal of a BST always gives sorted output
     
    
    printf("Characters in sorted alphabetical order:\n");
    printInOrder(root);
    printf("\n\n");

	// this will print the total number of unique nodes currently in the binary search tree (BST)
   
    insertedCount = countNodes(root);
    printf("Number of nodes in the tree: %d\n", insertedCount);

    // this will print the height of the binary search tree (BST)
    printf("Tree height: %d\n", treeHeight(root));

    
     // this is an optional example of using the search function
     
    letter = randomLowercaseChar();
    printf("\nSearch test for character '%c': ", letter);

    if (searchNode(root, letter) != NULL)
    {
        printf("Found in the tree.\n");
    }
    else
    {
        printf("Not found in the tree.\n");
    }

    // this will free all dynamically allocated memory before program ends
    freeTree(root);

    return 0;
}