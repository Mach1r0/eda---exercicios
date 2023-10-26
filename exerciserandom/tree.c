#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int root; 
    tree *left;
    tree *right;
} tree;

// This function counts the number of nodes in a binary tree.
int number_node(tree *raiz) {
    if (raiz == NULL) return 0; // empty tree, return 0
    int count = 1; // start with the root node
    int top = -1; // declare top of stack, -1 means empty stack
    tree *stack[500]; // declare stack
    stack[++top] = raiz; // push the root node onto the stack
    while (top != -1) { // run all the tree
        tree *current = stack[top--]; // pop the top node from the stack
        if (current->right != NULL) { // push the right child onto the stack (if it exists)
            stack[++top] = current->right;
            count++;
        }
        if (current->left != NULL) { // push the left child onto the stack (if it exists)
            stack[++top] = current->left;
            count++;
        }
    }
    return count; // return the total number of nodes in the tree
}